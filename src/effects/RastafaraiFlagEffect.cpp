/**
 * @project OpenHoop
 * @file RastafaraiFlagEffect.cpp
 * @brief Implementation file for the RastafaraiFlagEffect class.
 * @details Defines the methods for updating and controlling the Rastafarian flag-inspired color effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/RastafaraiFlagEffect.h"

/**
 * @brief Constructor for RastafaraiFlagEffect.
 * Initializes angle, angular speed, color offset, and flag colors.
 */
RastafaraiFlagEffect::RastafaraiFlagEffect()
    : angle(0.0f), angularSpeed(0.02f), colorOffset(0.1f), color1(0xFF0000), color2(0xFFFF00), color3(0x00FF00), numLeds(NUM_LEDS) {}

/**
 * @brief Start the RastafaraiFlagEffect.
 * Placeholder for any initialization logic if needed.
 */
void RastafaraiFlagEffect::start() {
}

/**
 * @brief Update the RastafaraiFlagEffect.
 * Update the position and color of each LED based on the current angle and color palette.
 */
void RastafaraiFlagEffect::update() {
    // Update position and color of each LED
    for (int i = 0; i < numLeds; i++) {
        auto portion = static_cast<float>(fmod((angle + static_cast<float>(i) * colorOffset) / (2 * PI), 1.0f));

        if (portion < 0.333f) {
            // 33.3% green
            uint8_t r = (color1 >> 16) & 0xFF;
            uint8_t g = (color1 >> 8) & 0xFF;
            uint8_t b = color1 & 0xFF;
            hoop.setPixelColor(i, r, g, b);
        } else if (portion < 0.667f) {
            // 33.3% yellow
            uint8_t r = (color2 >> 16) & 0xFF;
            uint8_t g = (color2 >> 8) & 0xFF;
            uint8_t b = color2 & 0xFF;
            hoop.setPixelColor(i, r, g, b);
        } else if (portion < 1.0f) {
            // 33.3% red
            uint8_t r = (color3 >> 16) & 0xFF;
            uint8_t g = (color3 >> 8) & 0xFF;
            uint8_t b = color3 & 0xFF;
            hoop.setPixelColor(i, r, g, b);
        }
    }

    angle += angularSpeed;
    if (angle >= 2 * PI) {
        angle -= 2 * PI;
    }

    hoop.show();
}

/**
 * @brief Stop the RastafaraiFlagEffect.
 * Fills the LED display with black color when stopping the effect.
 */
void RastafaraiFlagEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
