/**
 * @project OpenHoop
 * @file PulseEffect.cpp
 * @brief Implementation file for the PulseEffect class.
 * @details Defines the methods for the PulseEffect class, responsible for creating a pulsing color effect on the LED display based on gyroscope inclination.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/PulseEffect.h"
#include "../../include/Config.h"
#include "../../include/utils/EffectUtils.h"

PulseEffect::PulseEffect() : pulseSpeed(1), pulseBrightness(255), pulseIncrement(5), currentColorIndex(0) {
    colors[0] = Adafruit_NeoPixel::Color(34, 87, 122);   // Deep blue reminiscent of tranquil ocean waves
    colors[1] = Adafruit_NeoPixel::Color(56, 163, 165);  // Subtle greenish-blue representing serene depths
    colors[2] = Adafruit_NeoPixel::Color(87, 204, 153);  // Vibrant emerald portraying energy and vitality
    colors[3] = Adafruit_NeoPixel::Color(128, 237, 153); // Fresh light green symbolizing renewal and growth
    colors[4] = Adafruit_NeoPixel::Color(199, 249, 204); // Soft tea green evoking a sense of calm and balance
}

void PulseEffect::start() {
}

void PulseEffect::update() {
    // Get the inclination from the gyroscope
    float inclination = EffectUtils::getInclination();

    // Map the inclination to the range [0, 255]
    auto mappedInclination = static_cast<int>(EffectUtils::mapRange(static_cast<int>(inclination), 0, 360, 0, 255));

    // Calculate the current color index based on inclination
    currentColorIndex = mappedInclination / 51;

    // Calculate the current brightness based on inclination
    pulseBrightness = mappedInclination % 51 * 5;

    // Apply the pulse to all LEDs
    for (int i = 0; i < hoop.numPixels(); i++) {
        uint32_t color = EffectUtils::interpolateColor(colors[currentColorIndex], colors[(currentColorIndex + 1) % 5], i, hoop.numPixels());
        color = EffectUtils::applyBrightness(color, pulseBrightness);
        hoop.setPixelColor(i, EffectUtils::applyEnergySavingMode(color));
    }

    hoop.show();
}

void PulseEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
