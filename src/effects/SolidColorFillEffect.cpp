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
#include "../../include/utils/EffectUtils.h"

SolidColorFillEffect::SolidColorFillEffect(uint32_t color) : solidColor(color) {
}

void SolidColorFillEffect::start() {
    // Fill all LEDs with the specified solid color
    for (int i = 0; i < hoop.numPixels(); i++) {
        hoop.setPixelColor(i, EffectUtils::applyEnergySavingMode(solidColor));
    }
    hoop.show();
}

void SolidColorFillEffect::update() {
    // No dynamic updates needed for the solid color fill effect
}

void SolidColorFillEffect::stop() {
    // Turn off all LEDs when stopping the effect
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
