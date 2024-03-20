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

RainbowEffect::RainbowEffect() : hue(0) {}

void RainbowEffect::start() {
}

void RainbowEffect::update() {
    static constexpr uint8_t maxHueValue = 255;
    static uint16_t i = 0;

    for (int j = 0; j < hoop.numPixels(); j++) {
        hoop.setPixelColor(j, EffectUtils::applyEnergySavingMode(EffectUtils::Wheel((i + j) % maxHueValue)));
    }

    hoop.show();
    i++;
}

void RainbowEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
