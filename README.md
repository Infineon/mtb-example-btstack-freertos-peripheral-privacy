# Bluetooth&reg; peripheral privacy

This code example demonstrates the privacy features available to users in Bluetooth&reg; 5.0 and above using ModusToolbox&trade; software.

Features demonstrated:
1. Privacy modes as defined in Bluetooth&reg; spec 5.0 and above.
2. Use of persistent storage for bond data management.
3. Management and handling of bond data of multiple peer devices.

[View this README on GitHub.](https://github.com/Infineon/mtb-example-anycloud-ble-peripheral-privacy)

[Provide feedback on this code example.](https://cypress.co1.qualtrics.com/jfe/form/SV_1NTns53sK2yiljn?Q_EED=eyJVbmlxdWUgRG9jIElkIjoiQ0UyMzM3OTYiLCJTcGVjIE51bWJlciI6IjAwMi0zMzc5NiIsIkRvYyBUaXRsZSI6IkJsdWV0b290aCZyZWc7IHBlcmlwaGVyYWwgcHJpdmFjeSIsInJpZCI6ImFtbWwiLCJEb2MgdmVyc2lvbiI6IjEuMS4wIiwiRG9jIExhbmd1YWdlIjoiRW5nbGlzaCIsIkRvYyBEaXZpc2lvbiI6Ik1DRCIsIkRvYyBCVSI6IklDVyIsIkRvYyBGYW1pbHkiOiJCVEFCTEUifQ==)

## Requirements

- [ModusToolbox™ software](https://www.cypress.com/products/modustoolbox-software-environment) v2.4
- Board support package (BSP) minimum required version: 3.x
- Programming language: C
- Associated parts: All [PSoC&trade; 6 MCU](https://www.cypress.com/PSoC6) parts with CYW43012, or CYW4343W [AIROC™ Wi-Fi & Bluetooth® combo chips](https://www.cypress.com/products/airoc-wi-fi-combos)


## Supported toolchains (make variable 'TOOLCHAIN')

- GNU Arm® embedded compiler v9.3.1 (`GCC_ARM`) - Default value of `TOOLCHAIN`
- Arm&reg; compiler v6.13 (`ARM`)
- IAR C/C++ compiler v8.42.2 (`IAR`)

## Supported kits (make variable 'TARGET')

- [PSoC&trade; 62S2 Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CY8CKIT-062S2-43012) (`CY8CKIT-062S2-43012`) – Default value of `TARGET`
- [PSoC&trade; 6 Wi-Fi Bluetooth® prototyping kit](https://www.cypress.com/CY8CPROTO-062-4343W) (`CY8CPROTO-062-4343W`) 
- [PSoC&trade; 6 Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CY8CKIT-062-WiFi-BT) (`CY8CKIT-062-WIFI-BT`)
- [PSoC&trade; 62S1 Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CYW9P62S1-43438EVB-01) (`CYW9P62S1-43438EVB-01`)
- [PSoC&trade; 62S1 Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CYW9P62S1-43012EVB-01) (`CYW9P62S1-43012EVB-01`)
- [PSoC&trade; 62S2 evaluation kit](https://www.cypress.com/CY8CEVAL-062S2) (`CY8CEVAL-062S2`, `CY8CEVAL-062S2-LAI-4373M2`, `CY8CEVAL-062S2-MUR-43439M2`)

## Hardware setup
This example uses the board's default configuration. See the kit user guide to ensure that the board is configured correctly.


## Software setup

Download the CySmart app for [iOS](https://itunes.apple.com/us/app/cysmart/id928939093?mt=8) or [Android](https://play.google.com/store/apps/details?id=com.cypress.cysmart).

Scan the following QR codes from your mobile phone to download the CySmart app.

![AppQR](./images/qr.png)

Install a terminal emulator if you don't have one. Instructions in this document use [Tera Term](https://ttssh2.osdn.jp/index.html.en).


## Using the code example

Create the project and open it using one of the following:

<details><summary><b>In Eclipse IDE for ModusToolbox&trade; software</b></summary>

1. Click the **New Application** link in the **Quick Panel** (or, use **File** > **New** > **ModusToolbox Application**). This launches the [Project Creator](https://www.cypress.com/ModusToolboxProjectCreator) tool.

2. Pick a kit supported by the code example from the list shown in the **Project Creator - Choose Board Support Package (BSP)** dialog.

   When you select a supported kit, the example is reconfigured automatically to work with the kit. To work with a different supported kit later, use the [Library Manager](https://www.cypress.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can use the Library Manager to select or update the BSP and firmware libraries used in this application. To access the Library Manager, click the link from the **Quick Panel**.

   You can also just start the application creation process again and select a different kit.

   If you want to use the application for a kit not listed here, you may need to update the source files. If the kit does not have the required resources, the application may not work.

3. In the **Project Creator - Select Application** dialog, choose the example by enabling the checkbox.

4. (Optional) Change the suggested **New Application Name**.

5. The **Application(s) Root Path** defaults to the Eclipse workspace which is usually the desired location for the application. If you want to store the application in a different location, you can change the *Application(s) Root Path* value. Applications that share libraries should be in the same root path.

6. Click **Create** to complete the application creation process.

For more details, see the [Eclipse IDE for ModusToolbox&trade; software user guide](https://www.cypress.com/MTBEclipseIDEUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/ide_{version}/docs/mt_ide_user_guide.pdf*).

</details>

<details><summary><b>In command-line interface (CLI)</b></summary>

ModusToolbox&trade; software provides the Project Creator as both a GUI tool and the command line tool, "project-creator-cli". The CLI tool can be used to create applications from a CLI terminal or from within batch files or shell scripts. This tool is available in the *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/* directory.

Use a CLI terminal to invoke the "project-creator-cli" tool. On Windows, use the command line "modus-shell" program provided in the ModusToolbox&trade; software installation instead of a standard Windows command-line application. This shell provides access to all ModusToolbox&trade; software tools. You can access it by typing `modus-shell` in the search box in the Windows menu. In Linux and macOS, you can use any terminal application.

This tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--board-id` | Defined in the `<id>` field of the [BSP](https://github.com/Infineon?q=bsp-manifest&type=&language=&sort=) manifest | Required
`--app-id`   | Defined in the `<id>` field of the [CE](https://github.com/Infineon?q=ce-manifest&type=&language=&sort=) manifest | Required
`--target-dir`| Specify the directory in which the application is to be created if you prefer not to use the default current working directory | Optional
`--user-app-name`| Specify the name of the application if you prefer to have a name other than the example's default name | Optional
<br>

The following example will clone the "[Hello World](https://github.com/Infineon/mtb-example-psoc6-hello-world)" application with the desired name "MyHelloWorld" configured for the *CY8CKIT-062-WIFI-BT* BSP into the specified working directory, *C:/mtb_projects*:

   ```
   project-creator-cli --board-id CY8CKIT-062-WIFI-BT --app-id mtb-example-psoc6-hello-world --user-app-name MyHelloWorld --target-dir "C:/mtb_projects"
   ```

**Note:** The project-creator-cli tool uses the `git clone` and `make getlibs` commands to fetch the repository and import the required libraries. For details, see the "Project creator tools" section of the [ModusToolbox&trade; software user guide](https://www.cypress.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>

<details><summary><b>In third-party IDEs</b></summary>

Use one of the following options:

- **Use the standalone [Project Creator](https://www.cypress.com/ModusToolboxProjectCreator) tool:**

   1. Launch Project creator from the Windows Start menu or from *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/project-creator.exe*.

   2. In the initial **Choose Board Support Package** screen, select the BSP, and click **Next**.

   3. In the **Select Application** screen, select the appropriate IDE from the **Target IDE** drop-down menu.

   4. Click **Create** and follow the instructions printed in the bottom pane to import or open the exported project in the respective IDE.

<br>

- **Use command-line interface (CLI):**

   1. Follow the instructions from the **In command-line interface (CLI)** section to create the application, and then import the libraries using the `make getlibs` command.

   2. Export the application to a supported IDE using the `make <ide>` command.

   3. Follow the instructions displayed in the terminal to create or import the application as an IDE project.

For a list of supported IDEs and more details, see the "Exporting to IDEs" section of the [ModusToolbox&trade; software user guide](https://www.cypress.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>


## Operation

1. Connect the board to your PC using the provided USB cable through the KitProg3 USB connector.

2. Open a terminal program and select the KitProg3 COM port. Configure the terminal application to access the serial port using the following settings:

   Baud rate = 115200 bps; Data = 8 bits; Parity = None; Stop = 1 bit; Flow control = None; New line for receive data = Line Feed(LF) or Auto setting

3. Program the board using one of the following:

   <details><summary><b>Using Eclipse IDE for ModusToolbox&trade; software</b></summary>

      1. Select the application project in the Project Explorer.

      2. In the **Quick Panel**, scroll down, and click **\<Application Name> Program (KitProg3_MiniProg4)**.
   </details>

   <details><summary><b>Using CLI</b></summary>

     From the terminal, execute the `make program` command to build and program the application using the default toolchain to the default target. The default toolchain and target are specified in the application's Makefile but you can override those values manually:
      ```
      make program TARGET=<BSP> TOOLCHAIN=<toolchain>
      ```

      Example:
      ```
      make program TARGET=CY8CKIT-062S2-43012 TOOLCHAIN=GCC_ARM
      ```
   </details>
4. The application runs a custom button service with one custom characteristic that counts the number of button presses on the kit. It can be read or setup for notifications. Each time the button on the kit is pressed the count value is incremented. If any device is connected and has notifications enabled the updated value is sent to it. If no device is connected or notifications are disabled a message informing the same is displayed.

   **NOTE:** The button count is incremented on the button press irrespective of whether any device is connected or not.

5. Following instructions appear on the terminal on application start:
    * Press **'l'** to check for the number of bonded devices and next empty slot
        - This option allows you to identify how many devices are paired to the peripheral and which is the next available slot. This example supports upto four bonded devices after which the oldest devices data is overwritten.
    * Press **'d'** to erase all the bond data present in flash
        - This option allows you to clear the memory of all the current bond data.
    * Press **'e'** to enter the bonding mode and add devices to bond list
        - This option puts the peripheral into bonding mode allowing it to connect and bond with new devices. After connection and bonding, the incoming device can read and subscribe to the custom button count service.
    * Enter slot number to start directed advertisement for that device.
    * Press **'p'** to change the privacy mode of bonded device
        - This option is used to change the privacy mode setting of the bonded devices i.e to move the devices from network privacy mode to device privacy mode and vice versa. For more information about the privacy modes, read the design and implementation section.
    * Press **'h'** any time in application to print the menu
        - This option is used to request the Start menu options to view the options availabe at any point in the program.
    * Press **'r'** to reset kv-store (delete bond data and local IRK).

      - The stored data is persistent across power cycles and programming cycle. This option is used to clear the kv-store structures and data from the flash.

    Use these available commands to interact with the application. Refer [Figure 4](#Figure-4-Process-Flowchart) for the application flow chart.

    **Figure 1. Terminal output showing connection**
    ![](images/figure1.png)


6. Search for the available service and enable notifications. The Discovery should complete successfully and when the notifications are enabled, the application will get notified about each SW3 key press on the kit in form of total key presses so far.

    **Figure 2. Terminal output showing notification**
    ![](images/figure2.png)

## Design and implementation


### Introduction

The objective of the application is to demonstrate the privacy features available in the Bluetooth&reg; devices. Bluetooth&reg; devices implement privacy mainly by using **different types of addresses**: Public (no privacy) or Random. 

Random addresses can be Static (no periodical changes) or Private (periodical changes, offering privacy protection). Private addresses can be further divided into Non-resolvable or Resolvable.

The use of resolvable private addresses allows only the devices that are paired to your device to "identify" the device as a known device; all other devices will perceive the device as a new device, making it difficult to track. If the device uses non-resolvable private address, it will be perceived as a new device every time it changes its address. The address is changed at regular intervals and is configurable.

Every privacy-enabled Bluetooth&reg; LE device has a unique address called the Identity Address and an Identity Resolving Key (IRK). The Identity Address is the Public Address or Static Address of the Bluetooth&reg; LE device. The IRK is used by the Bluetooth&reg; LE device to generate its RPA and is used by peer devices to resolve the RPA of the Bluetooth&reg; LE device. Both the Identity Address and the IRK are exchanged during the pairing process. Privacy-enabled Bluetooth&reg; LE devices maintain a list that consists of the peer device’s Identity Address, the local IRK used by the Bluetooth&reg; LE device to generate its RPA, and the peer device’s IRK used to resolve the peer device’s RPA. This is called the Resolving List. Only peer devices that have the 128-bit IRK of a Bluetooth&reg; LE device can determine the device's address.


**Figure 3. Bluetooth&reg; LE address types**

![AddressTypes](images/address_types.jpg)

Bluetooth&reg; 5.0 introduces more options in the form of **privacy modes**.

There are two modes of privacy: device privacy and network privacy.

In **device privacy** mode, a device is only concerned about the privacy of the device and will accept advertising/connection packets from peer devices that contain their identity address as well as ones that contain a private address, even if the peer device has distributed its IRK in the past.

In **network privacy** mode, a device will only accept advertising/connection packets from peer devices that contain private addresses. By default, the network privacy mode is used when private addresses are resolved and generated by the controller.

[Table 2](#table-1-logical-representation-of-resolving-list-entries) shows the logical representation of the resolving list when a device that is trying to reconnect the controller checks the resolving list for the device. Based on the result two the following two cases can occur:

### 1. Device is found in the list:

**Table 1.Advertisement and connection address types**

|Advertisement/connection address type| Privacy mode  |Request accepted/rejected|
| ------------------------------------|---------------|-------------------------|
| Identity address                    | Network       | Rejected                |
| Identity address                    | Device        | Accepted                |
| Resolvable private address          | Network       | Accepted                |
| Resolvable private address          | Device        | Accepted                |

### 2. Device not found in the list:

    In this case, the incoming device is treated as a new device and the request is forwarded to the host by the controller for further processing.

**Note**: A device using non-resolvable private address will be treated as a new device on every reconnection.


**Table 2. Logical representation of resolving list entries**

| Device|Local IRK | Peer IRK  | Peer identity address  |Address type  | Privacy mode    |
| ------|----------|-----------|------------------------|--------------|-----------------|
| 1     |Local IRK | Peer IRK 1| Peer identity address 1|Address type 1| Network/device 1|
| 2     |Local IRK | Peer IRK 2| Peer identity address 2|Address type 2| Network/device 2|
| 3     |Local IRK | Peer IRK 3| Peer identity address 3|Address type 3| Network/device 3|

The application runs a custom button service with one custom characteristic that counts the number of button presses on the kit. It can be read or set up for notifications. The GATT DB is set up so that the characteristic can be read without pairing/bonding, but for enabling and disabling notifications pairing/bonding is required. Each time the button on the kit is pressed, the count value is incremented. If any device is connected and has notifications enabled, the updated value is sent to it. If no device is connected or notifications are disabled, a message informing the same is displayed.

The device can store bond data of upto four peer devices after which the data of the oldest device is overwritten by the new incoming device. The incoming device is added in network privacy mode by default.
The application supports UART based commands which can be used to issue privacy made change for the incoming device.

**NOTE** : The Tickless idle is disabled in the FreeRTOSConfig.h to allow the UART interrupts to be received as the application uses UART commands to control the functionality and take user input.

The peripheral has five states:

1. **IDLE_NO_DATA**: The device in this state is either waiting for the user input or advertising. No bond data is present in the NVRAM. Directed advertising option is disabled in this state.
2. **IDLE_DATA**: The device in this state is either waiting for the user input or advertising. Bond data is present in the NVRAM. Directed advertising option is available.
3. **IDLE_PRIVACY_CHANGE**: The device in this state is not advertising. The device enters this mode when command to change the privacy mode of bonded devices is issued.
4. **CONNECTED**: In this state, the peripheral is connected to a peer device.
5. **BONDED**: The peripheral moves into this state once it has has paired and bonded with the connected device and the peer bond information has been saved to NVRAM.

**Figure 3. Transition between different states**

![](images/figure3.png)

The LED 1 on the kit is used to represent the current advertising state of the device. [Table 2] shows LED behavior for different advertising states.

**Table 2. LED behavior for advertising states**
|Advertisement state           | LED state                       |
|------------------------------|---------------------------------|
|Advertisement ON (Undirected) | Slow Blinking led (T = 1 sec)   |
|Advertisement ON (Directed):  | Fast Blinking led (T = 200 msec)|
|Advertisement OFF, Connected: | LED ON                          |
|Advertisement OFF, Timed out: | LED OFF                         |

**Figure 4. Process flowchart**

![Flowchart](images/process_flow_chart.png)

## Resources and settings
This section explains the ModusToolbox&trade; software resources and their configuration as used in this code example. Note that all the configuration explained in this section has already been done in the code example.

- **Device configurator:** ModusToolbox&trade; software stores the device configuration settings of the application in the *design.modus* file. This file is used by the device configurator, which generate the configuration firmware. This file is stored in the respective kit BSP folder in *mtb_shared* project. For example, for CY8CKIT-062S2-43012 the path is *<workspace_path>mtb_shared\TARGET_CY8CKIT-062S2-43012\latest-v3.X\COMPONENT_BSP_DESIGN_MODUS/design.modus*.

  Similarly, bluetooth configuration settings are stored in the *cycfg_bt.cybt* (an xml file which contains configuration such as device name and information about GATT database). This xml file is present in the application folder.

* **Device configurator** The device configurator is used to enable/configure the peripherals and the pins used in the application. See the
[Device configurator guide](https://www.cypress.com/ModusToolboxDeviceConfig).

* **Bluetooth&reg; configurator:** The Bluetooth&reg; configurator is used for generating/modifying the Bluetooth&reg; LE GATT database. See the
[Bluetooth&reg; configurator guide](https://www.cypress.com/ModusToolboxBLEConfig).

## Related resources

Resources  | Links
-----------|----------------------------------
Application notes  | [AN228571](https://www.cypress.com/AN228571) – Getting started with PSoC&trade; 6 MCU on ModusToolbox&trade; software<br>  [AN221774](https://www.cypress.com/AN221774) – Getting started with PSoC&trade; 6 MCU on PSoC&trade; Creator<br> [AN210781](https://www.cypress.com/AN210781) – Getting started with PSoC&trade; 6 MCU with Bluetooth&reg; low energy (BLE) connectivity <br> [AN215656](https://www.cypress.com/AN215656) – PSoC&trade; 6 MCU: Dual-CPU system design
Code examples | [Using ModusToolbox&trade; software](https://github.com/Infineon/Code-Examples-for-ModusToolbox-Software) on GitHub| <br> [Using PSoC&trade; Creator](https://www.cypress.com/documentation/code-examples/psoc-6-mcu-code-examples) 
Device documentation | [PSoC&trade; 6 MCU datasheets](https://www.cypress.com/search/all?f[0]=meta_type%3Atechnical_documents&f[1]=resource_meta_type%3A575&f[2]=field_related_products%3A114026) <br> [PSoC&trade; 6 Technical reference manuals](https://www.cypress.com/search/all/PSoC%206%20Technical%20Reference%20Manual?f[0]=meta_type%3Atechnical_documents&f[1]=resource_meta_type%3A583) 
Development kits | Visit www.cypress.com/microcontrollers-mcus-kits and use the options in the **Select your kit** section to filter kits by *Product family* or *Features*.    
Libraries on GitHub  | [mtb-pdl-cat1](https://github.com/Infineon/mtb-pdl-cat1) – PSoC&trade; 6 peripheral driver library (PDL)  <br>  [mtb-hal-cat1](https://github.com/Infineon/mtb-hal-cat1) – Hardware abstraction layer (HAL) library and docs <br> [retarget-io](https://github.com/Infineon/retarget-io) – Utility library to retarget STDIO messages to a UART port <br>  [bluetooth-freeRTOS](https://github.com/Infineon/bluetooth-freertos) – Infineon&reg; WICED Bluetooth&reg;/Bluetooth&reg; LE host stack solution on GitHub <br> 
Middleware on GitHub | [capsense](https://github.com/Infineon/capsense) – CAPSENSE&trade; library and docs <br> [psoc6-middleware](https://github.com/Infineon/modustoolbox-software) – Links to all PSoC&trade; 6 MCU middleware
Tools | [Eclipse IDE for ModusToolbox&trade; software](https://www.cypress.com/modustoolbox) – ModusToolbox&trade; software is a collection of easy-to-use software and tools enabling rapid development with Infineon&reg; MCUs, covering applications from embedded sense and control to wireless and cloud-connected systems using AIROC&trade; Wi-Fi and Bluetooth® connectivity devices.
<br>

## Other resources

Cypress provides a wealth of data at www.cypress.com to help you select the right device, and quickly and effectively integrate it into your design.

For PSoC&trade; 6 MCU devices, see [How to design with PSoC&trade; 6 MCU - KBA223067](https://community.cypress.com/docs/DOC-14644) in the Cypress community.


## Document history

Document title: *CE233796* - *Bluetooth&reg; LE peripheral privacy*

| Version | Description of change |
| ------- | --------------------- |
| 1.1.0   | New code example      |

---------------------------------------------------------

© Cypress Semiconductor Corporation, 2020-2021. This document is the property of Cypress Semiconductor Corporation, an Infineon Technologies company, and its affiliates ("Cypress").  This document, including any software or firmware included or referenced in this document ("Software"), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide.  Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights.  If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress’s patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products.  Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.
<br>
TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  No computing device can be absolutely secure.  Therefore, despite security measures implemented in Cypress hardware or software products, Cypress shall have no liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. CYPRESS DOES NOT REPRESENT, WARRANT, OR GUARANTEE THAT CYPRESS PRODUCTS, OR SYSTEMS CREATED USING CYPRESS PRODUCTS, WILL BE FREE FROM CORRUPTION, ATTACK, VIRUSES, INTERFERENCE, HACKING, DATA LOSS OR THEFT, OR OTHER SECURITY INTRUSION (collectively, "Security Breach").  Cypress disclaims any liability relating to any Security Breach, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any Security Breach.  In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes.  It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product.  "High-Risk Device" means any device or system whose failure could cause personal injury, death, or property damage.  Examples of High-Risk Devices are weapons, nuclear installations, surgical implants, and other medical devices.  "Critical Component" means any component of a High-Risk Device whose failure to perform can be reasonably expected to cause, directly or indirectly, the failure of the High-Risk Device, or to affect its safety or effectiveness.  Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any use of a Cypress product as a Critical Component in a High-Risk Device. You shall indemnify and hold Cypress, including its affiliates, and its directors, officers, employees, agents, distributors, and assigns harmless from and against all claims, costs, damages, and expenses, arising out of any claim, including claims for product liability, personal injury or death, or property damage arising from any use of a Cypress product as a Critical Component in a High-Risk Device. Cypress products are not intended or authorized for use as a Critical Component in any High-Risk Device except to the limited extent that (i) Cypress’s published data sheet for the product explicitly states Cypress has qualified the product for use in a specific High-Risk Device, or (ii) Cypress has given you advance written authorization to use the product as a Critical Component in the specific High-Risk Device and you have signed a separate indemnification agreement.
<br>
Cypress, the Cypress logo, and combinations thereof, WICED, ModusToolbox, PSoC, CapSense, EZ-USB, F-RAM, and Traveo are trademarks or registered trademarks of Cypress or a subsidiary of Cypress in the United States or in other countries. For a more complete list of Cypress trademarks, visit cypress.com. Other names and brands may be claimed as property of their respective owners.
