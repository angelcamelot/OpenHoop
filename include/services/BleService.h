/**
 * @project OpenHoop
 * @file BleService.h
 * @brief Bluetooth Low Energy (BLE) service for the OpenHoop Smart LED Hula Hoop.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_BLESERVICE_H
#define OPENHOOP_BLESERVICE_H

#include <ArduinoBLE.h>

/**
 * @class BleService
 * @brief Manages the Bluetooth Low Energy (BLE) service for the OpenHoop.
 */
class BleService {
private:
    BLEService batteryService;  ///< Battery service for BLE.
    BLEByteCharacteristic batteryLevelCharacteristic;  ///< Battery level characteristic.

public:
    /**
     * @brief Constructor for BleService.
     */
    BleService();

    /**
     * @brief Initializes and advertises the BLE service.
     */
    void beginAndAdvertise();

    /**
     * @brief Updates the battery level characteristic.
     * @param voltage - The current battery voltage.
     */
    void updateBatteryLevel(float voltage);

    BLEByteCharacteristic effectCharacteristic;  ///< Effect characteristic for BLE.
    BLEStringCharacteristic solidColorCharacteristic;  ///< Solid color characteristic for BLE.
    BLEByteCharacteristic energySavingModeCharacteristic;  ///< Energy-saving mode characteristic.

private:
    BLEService hulaHoopService;  ///< Hula Hoop service for BLE.
    BLEDescriptor reportDescriptor;  ///< BLE descriptor for report.
    BLEByteCharacteristic reportMapCharacteristic;  ///< Report map characteristic.

    BLEService deviceInformationService;  ///< Device information service for BLE.
    BLECharacteristic pnpIdCharacteristic; ///< Plug and Play ID characteristic.
    BLEStringCharacteristic manufacturerCharacteristic; ///< Manufacturer characteristic.
    BLEStringCharacteristic modelCharacteristic; ///< Model characteristic.
    BLEStringCharacteristic serialNumberCharacteristic; ///< Serial number characteristic.
    BLEStringCharacteristic firmwareCharacteristic; ///< Firmware version characteristic.

    BLEService hulaHoopControlService;  ///< Hula Hoop control service for BLE.
};

#endif //OPENHOOP_BLESERVICE_H
