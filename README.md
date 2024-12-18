# Bluetooth&reg; LE peripheral privacy


This code example demonstrates the privacy features available to users in Bluetooth&reg; 5.0 and above using ModusToolbox&trade;.

Features demonstrated:
- Privacy modes as defined in Bluetooth&reg; spec 5.0 and above.
- Use of persistent storage for bond data management.
- Management and handling of bond data of multiple peer devices.

[View this README on GitHub.](https://github.com/Infineon/mtb-example-btstack-freertos-peripheral-privacy)

[Provide feedback on this code example.](https://cypress.co1.qualtrics.com/jfe/form/SV_1NTns53sK2yiljn?Q_EED=eyJVbmlxdWUgRG9jIElkIjoiQ0UyMzM3OTYiLCJTcGVjIE51bWJlciI6IjAwMi0zMzc5NiIsIkRvYyBUaXRsZSI6IkJsdWV0b290aCZyZWc7IExFIHBlcmlwaGVyYWwgcHJpdmFjeSIsInJpZCI6ImFtbWwiLCJEb2MgdmVyc2lvbiI6IjUuMS4wIiwiRG9jIExhbmd1YWdlIjoiRW5nbGlzaCIsIkRvYyBEaXZpc2lvbiI6Ik1DRCIsIkRvYyBCVSI6IklDVyIsIkRvYyBGYW1pbHkiOiJCVEFCTEUifQ==)


## Requirements

- [ModusToolbox&trade;](https://www.infineon.com/modustoolbox) v3.2 or later (tested with v3.3)
- Board support package (BSP) minimum required version for:
   - AIROC&trade; CYW920829M2EVK-02/CYW989829M2EVB-01/CYW989829M2EVB-01: v2.0.0
   - PSOC&trade; 6 MCU: v5.0.0
   - XMC&trade; XMC7000 MCU: v2.3.0
- Programming language: C
- Associated parts: All [XMC7000 MCU](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc7000-industrial-microcontroller-arm-cortex-m7/) and [PSOC&trade; 6 MCU](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/) with [AIROC&trade; CYW43xxx Wi-Fi & Bluetooth&reg; combo chips](https://www.infineon.com/cms/en/product/wireless-connectivity/airoc-wi-fi-plus-bluetooth-combos/), [PSOC&trade; 6 MCU with AIROC&trade; Bluetooth&reg; LE](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/psoc-63/), [AIROC&trade; CYW43022 Wi-Fi & Bluetooth&reg; combo chip](https://www.infineon.com/cms/en/product/wireless-connectivity/airoc-wi-fi-plus-bluetooth-combos/wi-fi-5-802.11ac/cyw43022)


## Supported toolchains (make variable 'TOOLCHAIN')

- GNU Arm&reg; Embedded Compiler v11.3.1 (`GCC_ARM`) – Default value of `TOOLCHAIN`
- Arm&reg; Compiler v6.22 (`ARM`)
- IAR C/C++ Compiler v9.50.2 (`IAR`)


## Supported kits (make variable 'TARGET')

- [AIROC&trade; CYW20829 Bluetooth&reg; LE Evaluation Kit](https://www.infineon.com/CYW920829M2EVK-02) (`CYW920829M2EVK-02`) – Default value of `TARGET`
- [PSOC&trade; 62S2 Wi-Fi Bluetooth&reg; Pioneer Kit](https://www.infineon.com/CY8CKIT-062S2-43012) (`CY8CKIT-062S2-43012`)
- [AIROC&trade; CYW89829 Bluetooth&reg; LE Evaluation Kit](https://www.infineon.com/cms/en/product/promopages/CYW89829-Bluetooth-LE-MCU) (`CYW989829M2EVB-01`, `CYW989829M2EVB-03`)
- [PSOC&trade; 6 Wi-Fi Bluetooth&reg; Prototyping Kit](https://www.infineon.com/CY8CPROTO-062-4343W) (`CY8CPROTO-062-4343W`)
- [PSOC&trade; 6 Wi-Fi Bluetooth&reg; Pioneer Kit](https://www.infineon.com/CY8CKIT-062-WIFI-BT) (`CY8CKIT-062-WIFI-BT`)
- [PSOC&trade; 62S1 Wi-Fi Bluetooth&reg; Pioneer Kit](https://www.infineon.com/CYW9P62S1-43438EVB-01) (`CYW9P62S1-43438EVB-01`)
- [PSOC&trade; 62S1 Wi-Fi Bluetooth&reg; Pioneer Kit](https://www.infineon.com/CYW9P62S1-43012EVB-01) (`CYW9P62S1-43012EVB-01`)
- [PSOC&trade; 62S2 Evaluation Kit](https://www.infineon.com/CY8CEVAL-062S2) (`CY8CEVAL-062S2`, `CY8CEVAL-062S2-LAI-4373M2`, `CY8CEVAL-062S2-MUR-43439M2`, `CY8CEVAL-062S2-CYW43022CUB`, `CY8CEVAL-062S2-CYW955513SDM2WLIPA`)
- [PSOC&trade; 6 Bluetooth&reg; LE Pioneer Kit](https://www.infineon.com/CY8CKIT-062-BLE) (`CY8CKIT-062-BLE`)
- [PSOC&trade; 6 Bluetooth&reg; LE Prototyping Kit](https://www.infineon.com/CY8CPROTO-063-BLE) (`CY8CPROTO-063-BLE`)
- [EZ-BLE Arduino Evaluation Board](https://www.infineon.com/cms/en/product/evaluation-boards/cyble-416045-eval/) (`CYBLE-416045-EVAL`)
- [XMC&trade; XMC7200 Evaluation Kit](https://www.infineon.com/KIT_XMC72_EVK) (`KIT_XMC72_EVK_MUR_43439M2`)


## Hardware setup

This example uses the board's default configuration. See the kit user guide to ensure that the board is configured correctly.

> **Note:** The PSOC&trade; 6 Bluetooth&reg; LE Pioneer Kit (CY8CKIT-062-BLE) and the PSOC&trade; 6 Wi-Fi Bluetooth&reg; Pioneer Kit (CY8CKIT-062-WIFI-BT) ship with KitProg2 installed. ModusToolbox&trade; requires KitProg3. Before using this code example, make sure that the board is upgraded to KitProg3. The tool and instructions are available in the [Firmware Loader](https://github.com/Infineon/Firmware-loader) GitHub repository. If you do not upgrade, you will see an error like "unable to find CMSIS-DAP device" or "KitProg firmware is out of date".

> **Note:** The AIROC&trade; CYW20829 Bluetooth&reg; Kit (CYW920829M2EVK-02) ships with KitProg3 version 2.21 installed. ModusToolbox&trade; requires KitProg3 with latest version 2.40. Before using this code example, make sure that the board is upgraded to KitProg3. The tool and instructions are available in the [Firmware Loader](https://github.com/Infineon/Firmware-loader) GitHub repository. If you do not upgrade, you will see an error such as "unable to find CMSIS-DAP device" or "KitProg firmware is out of date".


## Software setup

See the [ModusToolbox&trade; tools package installation guide](https://www.infineon.com/ModusToolboxInstallguide) for information about installing and configuring the tools package.

This code example requires a GAP Central and GATT Client device which can scan and connect to our device.
Download and install the AIROC&trade; Bluetooth&reg; Connect App for [iOS](https://apps.apple.com/in/app/airoc-bluetooth-connect-app/id6443702288) or [Android](https://play.google.com/store/apps/details?id=com.infineon.airocbluetoothconnect).

1. Scan the following QR codes from your mobile phone to download the AIROC&trade; Bluetooth&reg; Connect App.

   **Figure 1. QR code for apps**

   ![](./images/qr.png)

2. Install a terminal emulator if you don't have one. Instructions in this document use [Tera Term](https://teratermproject.github.io/index-en.html).


## Using the code example


### Create the project

The ModusToolbox&trade; tools package provides the Project Creator as both a GUI tool and a command line tool.

<details><summary><b>Use Project Creator GUI</b></summary>

1. Open the Project Creator GUI tool.

   There are several ways to do this, including launching it from the dashboard or from inside the Eclipse IDE. For more details, see the [Project Creator user guide](https://www.infineon.com/ModusToolboxProjectCreator) (locally available at *{ModusToolbox&trade; install directory}/tools_{version}/project-creator/docs/project-creator.pdf*).

2. On the **Choose Board Support Package (BSP)** page, select a kit supported by this code example. See [Supported kits](#supported-kits-make-variable-target).

   > **Note:** To use this code example for a kit not listed here, you may need to update the source files. If the kit does not have the required resources, the application may not work.

3. On the **Select Application** page:

   a. Select the **Applications(s) Root Path** and the **Target IDE**.

   > **Note:** Depending on how you open the Project Creator tool, these fields may be pre-selected for you.

   b. Select this code example from the list by enabling its check box.

   > **Note:** You can narrow the list of displayed examples by typing in the filter box.

   c. (Optional) Change the suggested **New Application Name** and **New BSP Name**.

   d. Click **Create** to complete the application creation process.

</details>


<details><summary><b>Use Project Creator CLI</b></summary>

The 'project-creator-cli' tool can be used to create applications from a CLI terminal or from within batch files or shell scripts. This tool is available in the *{ModusToolbox&trade; install directory}/tools_{version}/project-creator/* directory.

Use a CLI terminal to invoke the 'project-creator-cli' tool. On Windows, use the command-line 'modus-shell' program provided in the ModusToolbox&trade; installation instead of a standard Windows command-line application. This shell provides access to all ModusToolbox&trade; tools. You can access it by typing "modus-shell" in the search box in the Windows menu. In Linux and macOS, you can use any terminal application.

The following example clones the "[LE peripheral privacy](https://github.com/Infineon/mtb-example-btstack-freertos-peripheral-privacy)" application with the desired name "PeripheralPrivacy" configured for the *CYW920829M2EVK-02* BSP into the specified working directory, *C:/mtb_projects*:

   ```
   project-creator-cli --board-id CYW920829M2EVK-02 --app-id mtb-example-btstack-freertos-peripheral-privacy --user-app-name PeripheralPrivacy --target-dir "C:/mtb_projects"
   ```

The 'project-creator-cli' tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--board-id` | Defined in the <id> field of the [BSP](https://github.com/Infineon?q=bsp-manifest&type=&language=&sort=) manifest | Required
`--app-id`   | Defined in the <id> field of the [CE](https://github.com/Infineon?q=ce-manifest&type=&language=&sort=) manifest | Required
`--target-dir`| Specify the directory in which the application is to be created if you prefer not to use the default current working directory | Optional
`--user-app-name`| Specify the name of the application if you prefer to have a name other than the example's default name | Optional

> **Note:** The project-creator-cli tool uses the `git clone` and `make getlibs` commands to fetch the repository and import the required libraries. For details, see the "Project creator tools" section of the [ModusToolbox&trade; tools package user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at {ModusToolbox&trade; install directory}/docs_{version}/mtb_user_guide.pdf).

</details>


### Open the project

After the project has been created, you can open it in your preferred development environment.


<details><summary><b>Eclipse IDE</b></summary>

If you opened the Project Creator tool from the included Eclipse IDE, the project will open in Eclipse automatically.

For more details, see the [Eclipse IDE for ModusToolbox&trade; user guide](https://www.infineon.com/MTBEclipseIDEUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mt_ide_user_guide.pdf*).

</details>


<details><summary><b>Visual Studio (VS) Code</b></summary>

Launch VS Code manually, and then open the generated *{project-name}.code-workspace* file located in the project directory.

For more details, see the [Visual Studio Code for ModusToolbox&trade; user guide](https://www.infineon.com/MTBVSCodeUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mt_vscode_user_guide.pdf*).

</details>


<details><summary><b>Keil µVision</b></summary>

Double-click the generated *{project-name}.cprj* file to launch the Keil µVision IDE.

For more details, see the [Keil µVision for ModusToolbox&trade; user guide](https://www.infineon.com/MTBuVisionUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mt_uvision_user_guide.pdf*).

</details>


<details><summary><b>IAR Embedded Workbench</b></summary>

Open IAR Embedded Workbench manually, and create a new project. Then select the generated *{project-name}.ipcf* file located in the project directory.

For more details, see the [IAR Embedded Workbench for ModusToolbox&trade; user guide](https://www.infineon.com/MTBIARUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mt_iar_user_guide.pdf*).

</details>


<details><summary><b>Command line</b></summary>

If you prefer to use the CLI, open the appropriate terminal, and navigate to the project directory. On Windows, use the command-line 'modus-shell' program; on Linux and macOS, you can use any terminal application. From there, you can run various `make` commands.

For more details, see the [ModusToolbox&trade; tools package user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>


## Operation

1. Connect the board to your PC using the provided USB cable through the KitProg3 USB connector.

2. Open a terminal program and select the KitProg3 COM port. Set the serial port parameters to 8N1 and 115200 baud.

3. Program the board using one of the following:

   <details><summary><b>Using Eclipse IDE</b></summary>

      1. Select the application project in the Project Explorer.

      2. In the **Quick Panel**, scroll down, and click **\<Application Name> Program (KitProg3_MiniProg4)**.
   </details>


   <details><summary><b>In other IDEs</b></summary>

   Follow the instructions in your preferred IDE.
   </details>


   <details><summary><b>Using CLI</b></summary>

     From the terminal, execute the `make program` command to build and program the application using the default toolchain to the default target. The default toolchain is specified in the application's Makefile but you can override this value manually:
      ```
      make program TOOLCHAIN=<toolchain>
      ```

      Example:
      ```
      make program TOOLCHAIN=GCC_ARM
      ```
   </details>

4. The application runs a custom button service with one custom characteristic that counts the number of button presses on the kit. It can be read or setup for notifications. Each time the button on the kit is pressed the count value is incremented. If any device is connected and has notifications enabled, the updated value is sent to it. If no device is connected or notifications are disabled, a message informing the same is displayed.

   > **Note:** The button count is incremented on the button press irrespective of whether any device is connected or not.

5. Following instructions appear on the terminal on application start:
    * Press **'l'** to check for the number of bonded devices and the next empty slot.
        - This option allows you to identify how many devices are paired to the peripheral and which is the next available slot. This example supports up to four bonded devices after which the oldest devices data is overwritten.
    * Press **'d'** to erase all the bond data present in the flash.
        - This option allows you to clear the memory of all the current bond data.
    * Press **'e'** to enter the bonding mode and add devices to the bond list.
        - This option puts the peripheral into bonding mode, allowing it to connect and bond with new devices. After connection and bonding, the incoming device can read and subscribe to the custom button count service.
    * Enter the slot number to start a directed advertisement for that device.
    * Press **'p'** to change the privacy mode of the bonded device.
        - This option is used to change the privacy mode setting of the bonded devices, i.e., to move the devices from network privacy mode to device privacy mode and vice versa. For more information about the privacy modes, read the design and implementation section.
    * Press **'h'** any time in the application to print the menu.
        - This option is used to request the Start menu options to view the options available at any point in the program.
    * Press **'r'** to reset kv-store (delete bond data and local IRK).

      - The stored data is persistent across power cycles and programming cycle. This option is used to clear the kv-store structures and data from the flash.

   Use these available commands to interact with the application. See **Figure 6** in the [Design and implementation](#design-and-implementation) section for the application flowchart.

   **Figure 2. Terminal output showing connection**

   ![](images/figure1.png)


6. Search for the available service and enable notifications. The Discovery should complete successfully and when the notifications are enabled, the application will get notified about each SW3 key press on the kit in form of total key presses so far.

    **Figure 3. Terminal output showing notification**
    
    ![](images/figure2.png)


## Debugging

You can debug the example to step through the code.


<details><summary><b>In Eclipse IDE</b></summary>

Use the **\<Application Name> Debug (KitProg3_MiniProg4)** configuration in the **Quick Panel**. For details, see the "Program and debug" section in the [Eclipse IDE for ModusToolbox&trade; user guide](https://www.infineon.com/MTBEclipseIDEUserGuide).

> **Note:** **(Only while debugging)** On the CM4 CPU, some code in `main()` may execute before the debugger halts at the beginning of `main()`. This means that some code executes twice – once before the debugger stops execution, and again after the debugger resets the program counter to the beginning of `main()`. See [KBA231071](https://community.infineon.com/docs/DOC-21143) to learn about this and for the workaround.

</details>


<details><summary><b>In other IDEs</b></summary>

Follow the instructions in your preferred IDE.
</details>

> **Note:** Debugging is of limited value when there is an active Bluetooth&reg; LE connection because as soon as the Bluetooth&reg; LE device stops responding, the connection will get dropped.


## Design and implementation

The objective of the application is to demonstrate the privacy features available in the Bluetooth&reg; devices. Bluetooth&reg; devices implement privacy mainly by using **different types of addresses**: Public (no privacy) or Random.

Random addresses can be Static (no periodical changes) or Private (periodical changes, offering privacy protection). Private addresses can be further divided into Non-resolvable or Resolvable.

The use of resolvable private addresses allows only the devices that are paired to your device to "identify" the device as a known device; all other devices will perceive the device as a new device, making it difficult to track. If the device uses non-resolvable private address, it will be perceived as a new device every time it changes its address. The address is changed at regular intervals and is configurable.

Every privacy-enabled Bluetooth&reg; LE device has a unique address called the Identity Address and an Identity Resolving Key (IRK). The Identity Address is the Public Address or Static Address of the Bluetooth&reg; LE device. The IRK is used by the Bluetooth&reg; LE device to generate its RPA and is used by peer devices to resolve the RPA of the Bluetooth&reg; LE device. Both the Identity Address and the IRK are exchanged during the pairing process. Privacy-enabled Bluetooth&reg; LE devices maintain a list that consists of the peer device’s Identity Address, the local IRK used by the Bluetooth&reg; LE device to generate its RPA, and the peer device’s IRK used to resolve the peer device’s RPA. This is called the Resolving List. Only peer devices that have the 128-bit IRK of a Bluetooth&reg; LE device can determine the device's address.


**Figure 4. Bluetooth&reg; LE address types**

![](images/address_types.jpg)

Bluetooth&reg; 5.0 introduces more options in the form of **privacy modes**.

There are two modes of privacy: device privacy and network privacy.

In **device privacy** mode, a device is only concerned about the privacy of the device and will accept advertising/connection packets from peer devices that contain their identity address as well as ones that contain a private address, even if the peer device has distributed its IRK in the past.

In **network privacy** mode, a device will only accept advertising/connection packets from peer devices that contain private addresses. By default, the network privacy mode is used when private addresses are resolved and generated by the controller.

**Table 2** shows the logical representation of the resolving list when a device that is trying to reconnect the controller checks the resolving list for the device. Based on the result two the following two cases can occur:

### 1. Device is found in the list.

**Table 1. Advertisement and connection address types**

Advertisement/connection address type| Privacy mode  |Request accepted/rejected
------------------------------------|---------------|-------------------------
Identity address                    | Network       | Rejected                
Identity address                    | Device        | Accepted                
Resolvable private address          | Network       | Accepted                
Resolvable private address          | Device        | Accepted                

<br>

### 2. Device not found in the list.

In this case, the incoming device is treated as a new device and the request is forwarded to the host by the controller for further processing.

> **Note**: A device using non-resolvable private address will be treated as a new device on every reconnection.


**Table 2. Logical representation of resolving list entries**

Device|Local IRK | Peer IRK  | Peer identity address  |Address type  | Privacy mode
------|----------|-----------|------------------------|--------------|-----------------
1     |Local IRK | Peer IRK 1| Peer identity address 1|Address type 1| Network/device 1
2     |Local IRK | Peer IRK 2| Peer identity address 2|Address type 2| Network/device 2
3     |Local IRK | Peer IRK 3| Peer identity address 3|Address type 3| Network/device 3

<br>

The application runs a custom button service with one custom characteristic that counts the number of button presses on the kit. It can be read or set up for notifications. The GATT DB is set up so that the characteristic can be read without pairing/bonding, but for enabling and disabling notifications pairing/bonding is required. Each time the button on the kit is pressed, the count value is incremented. If any device is connected and has notifications enabled, the updated value is sent to it. If no device is connected or notifications are disabled, a message informing the same is displayed.

The device can store bond data of up to four peer devices after which the data of the oldest device is overwritten by the new incoming device. The incoming device is added in network privacy mode by default.
The application supports UART based commands which can be used to issue privacy made change for the incoming device.

> **Note:** The Tickless idle is disabled in the *FreeRTOSConfig.h* to allow the UART interrupts to be received as the application uses UART commands to control the functionality and take user input.

The peripheral has five states:

1. **IDLE_NO_DATA**: The device in this state is either waiting for the user input or advertising. No bond data is present in the NVRAM. Directed advertising option is disabled in this state.
2. **IDLE_DATA**: The device in this state is either waiting for the user input or advertising. Bond data is present in the NVRAM. Directed advertising option is available.
3. **IDLE_PRIVACY_CHANGE**: The device in this state is not advertising. The device enters this mode when command to change the privacy mode of bonded devices is issued.
4. **CONNECTED**: In this state, the peripheral is connected to a peer device.
5. **BONDED**: The peripheral moves into this state once it has paired and bonded with the connected device and the peer bond information has been saved to NVRAM.


**Figure 5. Transition between different states**

![](images/figure3.png)

The LED 1 on the kit is used to represent the current advertising state of the device. **Table 3** shows LED behavior for different advertising states.

**Table 3. LED behavior for advertising states**

Advertisement state           | LED state
------------------------------|---------------------------------
Advertisement ON (Undirected) | Slow Blinking led (T = 1 sec)
Advertisement ON (Directed):  | Fast Blinking led (T = 200 msec)
Advertisement OFF, Connected: | LED ON
Advertisement OFF, Timed out: | LED OFF

<br>

**Figure 6. Process flowchart**

![](images/process_flow_chart.png)


## Resources and settings

This section explains the ModusToolbox&trade; software resources and their configuration as used in this code example. Note that all the configuration explained in this section has already been done in the code example.

- **Device configurator:** ModusToolbox&trade; software stores the device configuration settings of the application in the *design.modus* file. This file is used by the device configurator, which generate the configuration firmware. This file is stored in the respective kit BSP folder in *mtb_shared* project. For example, for CY8CKIT-062S2-43012 the path is *<workspace_path>mtb_shared\TARGET_CY8CKIT-062S2-43012\latest-v3.X\COMPONENT_BSP_DESIGN_MODUS/design.modus*.

  Similarly, Bluetooth&reg; configuration settings are stored in the *cycfg_bt.cybt* (an XML file which contains configuration such as device name and information about GATT database). This xml file is present in the application folder.

  - **Device configurator:** The device configurator is used to enable/configure the peripherals and the pins used in the application. See the [Device configurator guide](https://www.infineon.com/ModusToolboxDeviceConfig).

  - **Bluetooth&reg; configurator:** The Bluetooth&reg; configurator is used for generating/modifying the Bluetooth&reg; LE GATT database. See the [Bluetooth&reg; configurator guide](https://www.infineon.com/ModusToolboxBLEConfig).

   > **Note:** For PSOC&trade; 6 Bluetooth&reg; LE based BSPs (CY8CKIT-062-BLE, CY8CPROTO-063-BLE, CYBLE-416045-EVAL) with support for AIROC&trade; BTSTACK, if you want to use bt-configurator tool, select the option 'AIROC&trade; BTSTACK with Bluetooth&reg; LE only (PSOC&trade; 6 with CYW43xxx Connectivity device)' from the dropdown to select the device. Do not use the option 'PSOC&trade; Bluetooth&reg; LE Legacy Stack (PSOC&trade; 6-BLE)' since it is not compatible with AIROC&trade; BTSTACK.

   > **Note:** A workaround has been provided in *app_bt_gatt_handler.c* for the known issue (section: v2.3.0) mentioned in [RELEASE.md](https://github.com/Infineon/psoc6cm0p/blob/master/RELEASE.md) of [psoc6cm0p](https://github.com/Infineon/psoc6cm0p) library. This ensures that the application can connect with different peer devices without having to manually forget the bond data.


## Related resources

Resources  | Links
-----------|----------------------------------
Application notes  | [AN228571](https://www.infineon.com/AN228571) – Getting started with PSOC&trade; 6 MCU on ModusToolbox&trade; <br> [AN215656](https://www.infineon.com/AN215656) – PSOC&trade; 6 MCU: Dual-CPU system design
Code examples  | [Using ModusToolbox&trade;](https://github.com/Infineon/Code-Examples-for-ModusToolbox-Software) on GitHub
Device documentation | [PSOC&trade; 6 MCU datasheets](https://documentation.infineon.com/html/psoc6/bnm1651211483724.html) <br> [PSOC&trade; 6 technical reference manuals](https://documentation.infineon.com/html/psoc6/zrs1651212645947.html)
Development kits | Select your kits from the [Evaluation board finder](https://www.infineon.com/cms/en/design-support/finder-selection-tools/product-finder/evaluation-board).
Libraries on GitHub  | [mtb-pdl-cat1](https://github.com/Infineon/mtb-pdl-cat1) – PSOC&trade; 6 Peripheral Driver Library (PDL)  <br> [mtb-hal-cat1](https://github.com/Infineon/mtb-hal-cat1) – Hardware Abstraction Layer (HAL) library <br> [retarget-io](https://github.com/Infineon/retarget-io) – Utility library to retarget STDIO messages to a UART port
Middleware on GitHub  | [capsense](https://github.com/Infineon/capsense) – CAPSENSE&trade; library and documents <br> [psoc6-middleware](https://github.com/Infineon/modustoolbox-software#psoc-6-middleware-libraries) – Links to all PSOC&trade; 6 MCU middleware
Tools  | [ModusToolbox&trade;](https://www.infineon.com/modustoolbox) – ModusToolbox&trade; software is a collection of easy-to-use libraries and tools enabling rapid development with Infineon MCUs for applications ranging from wireless and cloud-connected systems, edge AI/ML, embedded sense and control, to wired USB connectivity using PSOC&trade; Industrial/IoT MCUs, AIROC&trade; Wi-Fi and Bluetooth&reg; connectivity devices, XMC&trade; Industrial MCUs, and EZ-USB&trade;/EZ-PD&trade; wired connectivity controllers. ModusToolbox&trade; incorporates a comprehensive set of BSPs, HAL, libraries, configuration tools, and provides support for industry-standard IDEs to fast-track your embedded application development.

<br>


## Other resources

Infineon provides a wealth of data at [www.infineon.com](https://www.infineon.com) to help you select the right device, and quickly and effectively integrate it into your design.


## Document history

Document title: *CE233796* - *Bluetooth&reg; LE peripheral privacy*

Version | Description of change 
------- | --------------------- 
1.1.0   | New code example      
2.0.0   | Updated to support ModusToolbox&trade; software v3.0 and BSPs v4.X
2.1.0   | Added support for CY8CKIT-062-BLE, CY8CPROTO-063-BLE, CYBLE-416045-EVAL
2.2.0   | New Error Handling change
3.0.0   | Added support for CY8CEVAL-062S2-CYW43022CUB CYW989829M2EVB-01 and CYW920829M2EVK-02
4.0.0   | Added support for CYW989829M2EVB-03, BSP and BTStack-integration major update for *Bluetooth&reg; firmware
5.0.0   | Added support for CY8CEVAL-062S2-CYW955513SDM2WLIPA
5.1.0   | Updated to support ModusToolbox&trade; v3.3 <br> Added support for KIT_XMC72_EVK_MUR_43439M2
<br>


All referenced product or service names and trademarks are the property of their respective owners.

The Bluetooth&reg; word mark and logos are registered trademarks owned by Bluetooth SIG, Inc., and any use of such marks by Infineon is under license.


---------------------------------------------------------

© Cypress Semiconductor Corporation, 2020-2024. This document is the property of Cypress Semiconductor Corporation, an Infineon Technologies company, and its affiliates ("Cypress").  This document, including any software or firmware included or referenced in this document ("Software"), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide.  Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights.  If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress's patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products.  Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.
<br>
TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  No computing device can be absolutely secure.  Therefore, despite security measures implemented in Cypress hardware or software products, Cypress shall have no liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. CYPRESS DOES NOT REPRESENT, WARRANT, OR GUARANTEE THAT CYPRESS PRODUCTS, OR SYSTEMS CREATED USING CYPRESS PRODUCTS, WILL BE FREE FROM CORRUPTION, ATTACK, VIRUSES, INTERFERENCE, HACKING, DATA LOSS OR THEFT, OR OTHER SECURITY INTRUSION (collectively, "Security Breach").  Cypress disclaims any liability relating to any Security Breach, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any Security Breach.  In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes.  It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product.  "High-Risk Device" means any device or system whose failure could cause personal injury, death, or property damage.  Examples of High-Risk Devices are weapons, nuclear installations, surgical implants, and other medical devices.  "Critical Component" means any component of a High-Risk Device whose failure to perform can be reasonably expected to cause, directly or indirectly, the failure of the High-Risk Device, or to affect its safety or effectiveness.  Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any use of a Cypress product as a Critical Component in a High-Risk Device. You shall indemnify and hold Cypress, including its affiliates, and its directors, officers, employees, agents, distributors, and assigns harmless from and against all claims, costs, damages, and expenses, arising out of any claim, including claims for product liability, personal injury or death, or property damage arising from any use of a Cypress product as a Critical Component in a High-Risk Device. Cypress products are not intended or authorized for use as a Critical Component in any High-Risk Device except to the limited extent that (i) Cypress's published data sheet for the product explicitly states Cypress has qualified the product for use in a specific High-Risk Device, or (ii) Cypress has given you advance written authorization to use the product as a Critical Component in the specific High-Risk Device and you have signed a separate indemnification agreement.
<br>
Cypress, the Cypress logo, and combinations thereof, ModusToolbox, PSoC, CAPSENSE, EZ-USB, F-RAM, and TRAVEO are trademarks or registered trademarks of Cypress or a subsidiary of Cypress in the United States or in other countries. For a more complete list of Cypress trademarks, visit www.infineon.com. Other names and brands may be claimed as property of their respective owners.
