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
#include "../../include/utils/EffectUtils.h"
#include "../../include/Config.h"
#include <cmath>

/**
 * @brief Constructor for RastafaraiFlagEffect.
 * Initializes angle, angular speed, color offset, and flag colors.
 */
RastafaraiFlagEffect::RastafaraiFlagEffect()
    : angle(0.0f), angularSpeed(0.02f), colorOffset(0.1f),
      color1(EffectUtils::HSVtoRGB(0, 255, 255)),
      color2(EffectUtils::HSVtoRGB(60, 255, 255)),
      color3(EffectUtils::HSVtoRGB(120, 255, 255)),
      numLeds(NUM_LEDS) {}

/**
 * @brief Start the RastafaraiFlagEffect.
 * Placeholder for any initialization logic if needed.
 */
void RastafaraiFlagEffect::start() {
    // Initialization logic goes here
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
            hoop.setPixelColor(i, EffectUtils::applyEnergySavingMode(color1));
        } else if (portion < 0.667f) {
            // 33.3% yellow
            hoop.setPixelColor(i, EffectUtils::applyEnergySavingMode(color2));
        } else if (portion < 1.0f) {
            // 33.3% red
            hoop.setPixelColor(i, EffectUtils::applyEnergySavingMode(color3));
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
