/**
 * @project OpenHoop
 * @file FunkyEffect.cpp
 * @brief Implementation file for the FunkyEffect class.
 * @details Defines the methods to update the LED display with a dynamic and colorful effect.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/FunkyEffect.h"
#include "../../include/Config.h"

/**
 * @brief Constructor for FunkyEffect.
 */
FunkyEffect::FunkyEffect() : time(0.0) {
    // New color palette
    colors[0] = 0x008080;  // Teal
    colors[1] = 0xa4debf;  // Mint
    colors[2] = 0xef0041;  // Magenta
    colors[3] = 0xffe33d;  // Yellow
    colors[4] = 0xff5bd7;  // Pink
}

/**
 * @brief Initializes the Effect.
 */
void FunkyEffect::start() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}

/**
 * @brief Updates the Effect.
 */
void FunkyEffect::update() {
    // Algorithm to dynamically change the position and color of each LED
    for (int i = 0; i < hoop.getActivePixels(); i++) {
        // Calculate position and color based on time and current position
        auto position = static_cast<float>(sin((time + i) * 0.1) * 0.5 + 0.5);  // Example of sine function
        int hue = static_cast<int>((position + 1.0f) * 127.5f);
        uint32_t color = EffectUtils::HSVtoRGB(hue, 255, 255);
        uint8_t r = (color >> 16) & 0xFF;
        uint8_t g = (color >> 8) & 0xFF;
        uint8_t b = color & 0xFF;
        hoop.setPixelColor(i, r, g, b);
    }

    hoop.show();
    time++;
}

/**
 * @brief Stops the Effect.
 * Turns off all LEDs on the display.
 */
void FunkyEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
