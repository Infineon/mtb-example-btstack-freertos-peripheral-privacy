/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the Peripheral_Privacy Example
*              for ModusToolbox.
*
* Related Document: See README.md
*
*******************************************************************************
* Copyright 2021-2024, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/*******************************************************************************
*        Header Files
*******************************************************************************/
#include "app_flash_common.h"
#include "wiced_bt_stack.h"
#include "cybsp.h"
#include "cyhal.h"
#include "cy_retarget_io.h"
#include <FreeRTOS.h>
#include <task.h>
#include "cycfg_bt_settings.h"
#include "cybsp_bt_config.h"
#include "cybt_platform_config.h"
#include <queue.h>
#include "peripheral_privacy.h"
#include "cy_serial_flash_qspi.h"
#include "mtb_kvstore.h"
#include "cybt_platform_config.h"
#include "cybsp_bt_config.h"
#include "app_bt_bonding.h"
/******************************************************************
 * Variable Definitions
 ******************************************************************/

/* Queue for communication between UART ISR and UART Task*/
QueueHandle_t xUARTQueue;

/* Queue for communication with LED Task*/
QueueHandle_t xLEDQueue;

/* FreeRTOS task handle for button task. Button task is used to start advertisment
 * or enable/disable notification from peer */
TaskHandle_t  button_task_handle;

/**
 * Function Name:
 * main
 *
 * Function Description:
 * @brief   Entry point to the application. Initialize transport configuration
 *          and register BLE management event callback. The actual application
 *          initialization will happen when stack reports that BT device is ready
 *
 * @param   None
 *
 * @return  int
 *
 */
int main()
{
    cy_rslt_t cy_result;
    wiced_result_t wiced_result;

    /*Initialize the block device used by kv-store for perfroming read/write operations to the flash*/
    app_kvstore_bd_config(&block_device);

    /* Initialize the board support package */
    cy_result = cybsp_init();
    cyhal_syspm_lock_deepsleep();

    /* Enable global interrupts */
    __enable_irq();

    /* Initialize retarget-io to use the debug UART port */
    cy_result = cy_retarget_io_init_fc(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX,CYBSP_DEBUG_UART_CTS,CYBSP_DEBUG_UART_RTS,CY_RETARGET_IO_BAUDRATE);
    if (cy_result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    printf("************* Peripheral Privacy App Start***** ************************\n");
    display_menu();

    if (CY_RSLT_SUCCESS != cy_result)
    {
        printf("BSP Initialization has failed! \n");
        CY_ASSERT(0);
    }

    /* Create a queue capable of unsigned integer values.
       this is used for communicating between UART ISR and the UART task */
    xUARTQueue = xQueueCreate( QUEUE_SIZE, sizeof(uint8_t) );

    /*Check the status of Queue creation*/
    if(NULL == xUARTQueue)
    {
        printf("Failed to create Queue for communication between UART ISR and Task!!");
        CY_ASSERT(0);
    }

    /* Create a queue capable of unsigned integer values.
       this is used for communicating with LED task */
    xLEDQueue = xQueueCreate( QUEUE_SIZE, sizeof(uint8_t) );

    /*Check the status of Queue creation*/
    if(NULL == xLEDQueue)
    {
        printf("Failed to create Queue for communication with LED Task!!");
    }

    /* Configure the Button GPIO */
    key_button_app_init();

    /* Create Button Task for processing button presses */
    if( pdPASS != xTaskCreate(button_task,"button_task", BUTTON_TASK_STACK_SIZE,
                                NULL, BUTTON_TASK_PRIORITY, &button_task_handle))
    {
        printf("Failed to create Button task!\n");
        CY_ASSERT(0);
    }

    /* Create UART Task for processing UART commands */
    if( pdPASS != xTaskCreate(uart_task,"uart_task",UART_TASK_STACK_SIZE,NULL,
                              UART_TASK_PRIORITY,NULL))
    {
        printf("Failed to create UART task!\n");
        CY_ASSERT(0);
    }

    /* Create the LED task. */
    if (pdPASS != xTaskCreate(app_led_control, "LED task", LED_TASK_STACK_SIZE,
                              NULL, LED_TASK_PRIORITY, NULL))
    {
        printf("Failed to create BLE task!\n");
        CY_ASSERT(0);
    }

    /* Register a callback function and set it to fire for any received UART characters */
    cyhal_uart_register_callback(&cy_retarget_io_uart_obj, uart_interrupt_handler,NULL);
    cyhal_uart_enable_event(&cy_retarget_io_uart_obj, CYHAL_UART_IRQ_RX_NOT_EMPTY, INT_PRIORITY, TRUE);

    /* Configure platform specific settings for the BT device */
    cybt_platform_config_init(&cybsp_bt_platform_cfg);

    /* Register call back and configuration with stack */
    wiced_result = wiced_bt_stack_init(app_bt_management_callback, &wiced_bt_cfg_settings);

    /* Check if stack initialization was successful */
    if (WICED_BT_SUCCESS == wiced_result)
    {
        printf("Bluetooth Stack Initialization Successful \n");
    }
    else
    {
        printf("Bluetooth Stack Initialization failed!! \n");
        CY_ASSERT(0);
    }

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    /* Should never get here */
    CY_ASSERT(0);
}
