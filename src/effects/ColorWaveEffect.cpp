/**
 * @project OpenHoop
 * @file ColorWaveEffect.cpp
 * @brief Implementation file for the ColorWaveEffect class, representing an LED effect with a color wave pattern.
 * @details Defines the methods to start, update, and stop the color wave effect.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/ColorWaveEffect.h"
#include "../../include/utils/EffectUtils.h"
#include "../../include/Config.h"

ColorWaveEffect::ColorWaveEffect() : waveSpeed(5), hueOffset(0), saturation(255), brightness(255) {}

void ColorWaveEffect::start() {
    hueOffset = 0; // Ensure resetting the offset at the beginning of the effect
}

void ColorWaveEffect::update() {
    for (int i = 0; i < hoop.numPixels(); i++) {
        int hue = (i * waveSpeed + hueOffset) % 256;
        uint32_t color = EffectUtils::HSVtoRGB(hue, saturation, brightness);
        hoop.setPixelColor(i, EffectUtils::applyEnergySavingMode(color));
    }
    hoop.show();
    hueOffset = (hueOffset + 1) % 256;
}

void ColorWaveEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
