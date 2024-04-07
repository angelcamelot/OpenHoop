/**
 * @project OpenHoop
 * @file SolidColorFillEffect.cpp
 * @brief Source file for the SolidColorFillEffect class.
 * @details Implements methods for starting, updating, and stopping the solid color fill effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/SolidColorFillEffect.h"
#include "../../include/Config.h"

/**
 * @brief Constructor for SolidColorFillEffect.
 */
SolidColorFillEffect::SolidColorFillEffect(uint32_t color) : solidColor(color) {
}

/**
 * @brief Initializes the Effect.
 */
void SolidColorFillEffect::start() {
    // Fill all LEDs with the specified solid color
    for (int i = 0; i < hoop.numPixels(); i++) {
        uint8_t r = (solidColor >> 16) & 0xFF;
        uint8_t g = (solidColor >> 8) & 0xFF;
        uint8_t b = solidColor & 0xFF;
        hoop.setPixelColor(i, r, g, b);
    }
    hoop.show();
}

/**
 * @brief Updates the Effect.
 */
void SolidColorFillEffect::update() {
    // No dynamic updates needed for the solid color fill effect
}

/**
 * @brief Stops the Effect.
 * Turns off all LEDs on the display.
 */
void SolidColorFillEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
