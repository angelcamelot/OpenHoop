/**
 * @project OpenHoop
 * @file Config.h
 * @brief Configuration file for the OpenHoop project.
 * @details This file contains pin configurations, constants, and UUIDs used throughout the project.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_CONFIG_H
#define OPENHOOP_CONFIG_H

#include <Adafruit_NeoPixel.h>

// Pin configuration for reading battery voltage.
#define BATTERY_ANALOG_PIN 21  ///< Analog pin used for reading battery voltage.
#define BATTERY_MAX_READING 1024.0  ///< Maximum ADC reading for battery.
#define BATTERY_MIN_VOLTAGE 5  ///< Minimum voltage considered for the battery.
#define BATTERY_MAX_VOLTAGE 8.4  ///< Maximum voltage for a fully charged battery.
#define R1 30000.0  ///< Resistance value R1 in Ohms.
#define R2 7500.0   ///< Resistance value R2 in Ohms.
#define REF_VOLTAGE 3.3  ///< Reference voltage in volts.

// LED configuration for the hoop.
#define NUM_LEDS 63  ///< Number of LEDs in the hoop.
#define LEDS_PIN 11  ///< Pin number to which the LEDs are connected.

// Bluetooth configuration.
#define EFFECT_SERVICE_UUID "0A92"  ///< UUID for the effect service.
#define SCOLOR_SERVICE_UUID "0A93"  ///< UUID for the solid color service.
#define ENERGY_SERVICE_UUID "0A95"  ///< UUID for the energy saving service.
#define MANUFACTURER_CHARACTERISTIC "OpenHoop"  ///< Manufacturer characteristic.
#define MODEL_CHARACTERISTIC "HulaHoopBLE"  ///< Model characteristic.
#define SERIAL_NUMBER_CHARACTERISTIC "HH-BLE-1"  ///< Serial number characteristic.
#define FIRMWARE_CHARACTERISTIC "v1.0.0"  ///< Firmware version characteristic.

// NeoPixel hoop object.
extern Adafruit_NeoPixel hoop;  ///< Object representing the NeoPixel hoop.

#endif //OPENHOOP_CONFIG_H
