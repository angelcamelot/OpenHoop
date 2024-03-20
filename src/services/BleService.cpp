/**
 * @project OpenHoop
 * @file BleService.cpp
 * @brief Implementation of the BleService class for handling BLE communication.
 * @details This file contains the definitions of methods for initializing BLE services, advertising the HulaHoop device,
 * and updating battery level characteristics.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/services/BleService.h"
#include "../../include/Config.h"

/**
 * @class BleService
 * @brief Handles BLE communication for the HulaHoop device.
 * @details This class initializes and configures BLE services and characteristics for the HulaHoop, including battery level,
 * effects control, solid color settings, energy-saving mode, and device information.
 */

/**
 * @brief Constructor for BleService class.
 * Initializes BLE services and characteristics.
 */
BleService::BleService():
        batteryService("180F"),
        batteryLevelCharacteristic("2A19", BLERead | BLENotify),
        effectCharacteristic(EFFECT_SERVICE_UUID, BLERead | BLEWrite),
        solidColorCharacteristic(SCOLOR_SERVICE_UUID, BLERead | BLEWrite, 8),
        energySavingModeCharacteristic(ENERGY_SERVICE_UUID, BLERead | BLEWrite),
        hulaHoopService("1812"),
        reportDescriptor("2908", "04 0B 00 0B 00 03 00 00 00 00 00 00 00 00 00 00 00 00 00 00"),
        reportMapCharacteristic("2A4B", BLERead | BLENotify),
        deviceInformationService("180A"),
        pnpIdCharacteristic("2A50", BLERead, 7),
        manufacturerCharacteristic("2A29", BLERead, 30),
        modelCharacteristic("2A24", BLERead, 20),
        serialNumberCharacteristic("2A25", BLERead, 15),
        firmwareCharacteristic("2A26", BLERead, 10),
        hulaHoopControlService("1815") {}

/**
 * @brief Begin BLE communication and advertise the HulaHoop device.
 */
void BleService::beginAndAdvertise() {
    // BLE setup
    BLE.begin();
    BLE.setDeviceName(MANUFACTURER_CHARACTERISTIC);
    BLE.setLocalName(MODEL_CHARACTERISTIC);
    BLE.setAppearance(0x04C0);
    BLE.setAdvertisedService(hulaHoopService);

    // Configure Report Map
    reportMapCharacteristic.addDescriptor(reportDescriptor);
    uint8_t reportMap[] = {
            0x05, 0x0C,       // Usage Page (Consumer Devices)
            0x09, 0x01,       // Usage (Battery Strength)
            0x15, 0x00,       // Logical Minimum (0)
            0x26, 0xFF, 0x00, // Logical Maximum (255)
            0x75, 0x08,       // Report Size (8 bits)
            0x95, 0x01,       // Report Count (1)
            0x81, 0x02        // Input (Data, Variable, Absolute)
    };
    for (unsigned char i : reportMap) {
        reportMapCharacteristic.writeValue(i);
    }
    hulaHoopService.addCharacteristic(reportMapCharacteristic);
    hulaHoopControlService.addCharacteristic(effectCharacteristic);
    effectCharacteristic.writeValue(-1);
    hulaHoopControlService.addCharacteristic(solidColorCharacteristic);
    solidColorCharacteristic.writeValue("NO COLOR");
    hulaHoopControlService.addCharacteristic(energySavingModeCharacteristic);
    energySavingModeCharacteristic.writeValue(0);
    deviceInformationService.addCharacteristic(pnpIdCharacteristic);
    deviceInformationService.addCharacteristic(manufacturerCharacteristic);
    deviceInformationService.addCharacteristic(modelCharacteristic);
    deviceInformationService.addCharacteristic(serialNumberCharacteristic);
    deviceInformationService.addCharacteristic(firmwareCharacteristic);
    batteryLevelCharacteristic.writeValue(0);
    batteryService.addCharacteristic(batteryLevelCharacteristic);

    uint8_t pnpIdData[] = {
            0x01,             // Vendor ID (1)
            0x0D,             // Product ID (13)
            0x00, 0x00,       // Version Number (0.0)
            0x11, 0x22, 0x33  // Serial Number
    };
    pnpIdCharacteristic.writeValue(pnpIdData, sizeof(pnpIdData));

    manufacturerCharacteristic.writeValue(MANUFACTURER_CHARACTERISTIC);
    modelCharacteristic.writeValue(MODEL_CHARACTERISTIC);
    serialNumberCharacteristic.writeValue(SERIAL_NUMBER_CHARACTERISTIC);
    firmwareCharacteristic.writeValue(FIRMWARE_CHARACTERISTIC);

    BLE.addService(hulaHoopService);
    BLE.addService(hulaHoopControlService);
    BLE.addService(batteryService);
    BLE.addService(deviceInformationService);

    BLE.setAdvertisingInterval(152);
    BLE.advertise();
}

/**
 * @brief Update the battery level characteristic based on the provided voltage.
 * @param voltage Voltage level of the battery.
 */
void BleService::updateBatteryLevel(float voltage) {
    // Calculate the battery level and update the BLE characteristic
    int batteryLevel = map(static_cast<long>(voltage * 100), static_cast<long>(BATTERY_MIN_VOLTAGE * 100), static_cast<long>(BATTERY_MAX_VOLTAGE * 100), 0, 100);
    batteryLevelCharacteristic.writeValue(batteryLevel);
}
