/**
 * @project OpenHoop
 * @file main.cpp
 * @brief Main program file for the OpenHoop project.
 * @details This file contains the setup and loop functions for the HulaHoop device, handling BLE communication,
 * updating battery levels, and managing LED effects.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include <Arduino.h>
#include "../include/services/BleService.h"
#include "../include/services/EffectService.h"
#include "../include/utils/EffectUtils.h"
#include "../include/Config.h"

HulaHoopNeoPixel hoop(NUM_LEDS, LEDS_PIN, NEO_GRB + NEO_KHZ800);

BleService bleService;
std::unique_ptr<EffectService> effectService = std::make_unique<EffectService>();

void setup() {
    // Initialize the PDM library for sound processing
    PDM.onReceive(EffectUtils::onPDMdata);

    // Initialize NeoPixel hoop
    hoop.begin();
    hoop.show();

    // Initialize NeoPixel BLE services
    bleService.beginAndAdvertise();
}

/**
 * @brief Update BLE communication, check for incoming commands.
 * Handles color code writes, gesture commands, and energy-saving mode changes.
 */
void updateBLE() {
    BLEDevice central = BLE.central();
    // Check for color code writes
    if (bleService.solidColorCharacteristic.written()) {
        String colorString = bleService.solidColorCharacteristic.value();
        effectService->dispatchSolidColorCommand(colorString);
        Serial.print("Color Command Received: ");
        Serial.println(colorString);
        bleService.effectCharacteristic.writeValue(-1);
    }

    // Check for gesture commands
    if (bleService.effectCharacteristic.written()) {
        auto gesture = static_cast<EffectType>(bleService.effectCharacteristic.value());
        effectService->dispatchEffectCommand(gesture);
        Serial.print("Effect Command Received: ");
        Serial.println(static_cast<int>(gesture));
        bleService.solidColorCharacteristic.writeValue("NO COLOR");
    }

    // Check for energy-saving mode writes
    if (bleService.energySavingModeCharacteristic.written()) {
        uint8_t energySavingMode = bleService.energySavingModeCharacteristic.value();
        hoop.setEnergySavingMode(energySavingMode);
    }
}

/**
 * @brief Update battery level based on the analog reading.
 */
void updateBatteryLevel() {
    int adcValue = analogRead(BATTERY_ANALOG_PIN);
    auto adcVoltage = static_cast<float>((adcValue * REF_VOLTAGE) / BATTERY_MAX_READING);
    auto batteryVoltage = static_cast<float>(adcVoltage * (R1 + R2) / R2);
    bleService.updateBatteryLevel(batteryVoltage);
}

void loop() {
    // Update BLE communication, check for incoming commands
    updateBLE();

    // Update battery level based on analog reading
    updateBatteryLevel();

    // Update LED effects
    effectService->update();
}
