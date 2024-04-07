/**
 * @project OpenHoop
 * @file HulaHoopNeoPixel.cpp
 * @brief Implementation file for the HulaHoopNeoPixel class, providing functionality for managing NeoPixels with
 * energy-saving modes.
 * @details This class extends the Adafruit_NeoPixel library to include energy-saving modes and dynamic pixel
 * management.
 * @author github.com/angelcamelot
 * @date 2024-04-07
 * @license Open-source license.
 */

#include "../../include/utils/HulaHoopNeoPixel.h"

/**
 * @brief Constructor for the HulaHoopNeoPixel class.
 * @param n Number of NeoPixels.
 * @param p Pin number.
 * @param t NeoPixel type.
 */
HulaHoopNeoPixel::HulaHoopNeoPixel(uint16_t n, uint8_t p, neoPixelType t) : Adafruit_NeoPixel(n, p, t), brightnessLevel(255), activePixels(n), energySavingModeLevel(0) {}

/**
 * @brief Applies energy-saving mode to the specified level.
 * @param level Energy-saving mode level (0-8).
 */
void HulaHoopNeoPixel::applyEnergySavingMode(uint8_t level) {
    switch (level) {
        case 0: // No energy saving mode
            energySavingModeLevel = 0;
            activePixels = numPixels();
            brightnessLevel = 255;
            break;
        case 1: // All pixels at 70% brightness
            energySavingModeLevel = 1;
            activePixels = numPixels();
            brightnessLevel = 178;
            break;
        case 2: // All pixels at 40% brightness
            energySavingModeLevel = 2;
            activePixels = numPixels();
            brightnessLevel = 102;
            break;
        case 3: // Half of pixels at 100% brightness
            energySavingModeLevel = 3;
            activePixels = numPixels() / 2;
            break;
        case 4: // Half of pixels at 70% brightness
            energySavingModeLevel = 4;
            activePixels = numPixels() / 2;
            brightnessLevel = 178;
            break;
        case 5: // Half of pixels at 40% brightness
            energySavingModeLevel = 5;
            activePixels = numPixels() / 2;
            brightnessLevel = 102;
            break;
        case 6: // Third of pixels at 100% brightness
            energySavingModeLevel = 6;
            activePixels = numPixels() / 3;
            break;
        case 7: // Third of pixels at 70% brightness
            energySavingModeLevel = 7;
            activePixels = numPixels() / 3;
            brightnessLevel = 178;
            break;
        case 8: // Third of pixels at 40% brightness
            energySavingModeLevel = 8;
            activePixels = numPixels() / 3;
            brightnessLevel = 102;
            break;
        default:
            // Invalid mode
            break;
    }
}

/**
 * @brief Override of setPixelColor to apply energy saving mode.
 * @param n Pixel number.
 * @param r Red color value.
 * @param g Green color value.
 * @param b Blue color value.
 */
void HulaHoopNeoPixel::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
    if (n < activePixels) {
        switch (energySavingModeLevel) {
            case 0:
            case 1:
            case 2:
                Adafruit_NeoPixel::setPixelColor(n, r * brightnessLevel / 255, g * brightnessLevel / 255, b * brightnessLevel / 255);
                break;
            case 3:
            case 4:
            case 5:
                Adafruit_NeoPixel::setPixelColor(n * 2, r * brightnessLevel / 255, g * brightnessLevel / 255, b * brightnessLevel / 255);
                break;
            case 6:
            case 7:
            case 8:
                Adafruit_NeoPixel::setPixelColor(n * 3, r * brightnessLevel / 255, g * brightnessLevel / 255, b * brightnessLevel / 255);
                break;
            default:
                break;
        }
    }
}

/**
 * @brief Sets the energy-saving mode level.
 * @param level Energy-saving mode level (0-8).
 */
void HulaHoopNeoPixel::setEnergySavingMode(uint8_t level) {
    applyEnergySavingMode(level);
}

/**
 * @brief Gets the number of active pixels.
 * @return Number of active pixels.
 */
uint16_t HulaHoopNeoPixel::getActivePixels() {
    return activePixels;
}
