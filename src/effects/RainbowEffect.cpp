/**
 * @project OpenHoop
 * @file RainbowEffect.cpp
 * @brief Implementation file for the RainbowEffect class.
 * @details Defines the methods for the RainbowEffect class, responsible for creating a rainbow color effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/RainbowEffect.h"
#include "../../include/utils/EffectUtils.h"
#include "../../include/Config.h"

/**
 * @brief Constructor for RainbowEffect.
 */
RainbowEffect::RainbowEffect() : hue(0) {}

/**
 * @brief Initializes the Effect.
 */
void RainbowEffect::start() {
}

/**
 * @brief Updates the Effect.
 */
void RainbowEffect::update() {
    static constexpr uint8_t maxHueValue = 255;
    static uint16_t i = 0;

    for (int j = 0; j < hoop.getActivePixels(); j++) {
        uint32_t color = EffectUtils::Wheel((i + j) % maxHueValue);
        uint8_t r = (color >> 16) & 0xFF;
        uint8_t g = (color >> 8) & 0xFF;
        uint8_t b = color & 0xFF;
        hoop.setPixelColor(j, r, g, b);
    }

    hoop.show();
    i++;
}

/**
 * @brief Stops the Effect.
 * Turns off all LEDs on the display.
 */
void RainbowEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
