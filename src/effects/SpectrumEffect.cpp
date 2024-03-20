/**
 * @project OpenHoop
 * @file SpectrumEffect.cpp
 * @brief Implementation file for the SpectrumEffect class.
 * @details Implements the methods for creating a spectrum color effect on the LED display in response to sound intensity.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/SpectrumEffect.h"
#include "../../include/Config.h"

SpectrumEffect::SpectrumEffect() : hue(0), wavePosition(0) {}

void SpectrumEffect::start() {
    PDM.begin(1, 16000);
}

void SpectrumEffect::update() {
    int soundIntensity = EffectUtils::calculateSoundSpectrum();

    // Calculate the color of the sound wave
    int waveBlueComponent = constrain(hue * 2, 0, 255);
    int waveGreenComponent = constrain(hue, 0, 255);
    int waveEffect = static_cast<int>(sin(radians(wavePosition)) * 127 + 128);
    uint32_t waveColor = Adafruit_NeoPixel::Color(0, waveGreenComponent + waveEffect, waveBlueComponent);

    // Calculate the inverted color for the hoop background
    uint32_t invertedBackgroundColor = Adafruit_NeoPixel::Color(255 - (waveGreenComponent + waveEffect), 255 - waveBlueComponent, 255 - waveGreenComponent);

    // Calculate the number of active pixels based on the sound percentage
    int activePixels = EffectUtils::mapRange(soundIntensity, 1, 10, 1, hoop.numPixels());

    // Apply the inverted background color to all LEDs
    hoop.fill(invertedBackgroundColor);

    // Apply the wave color to the active pixels
    for (int i = 0; i < activePixels; i++) {
        hoop.setPixelColor(i, EffectUtils::applyEnergySavingMode(waveColor));
    }

    hoop.show();

    // Update the wave position
    wavePosition += soundIntensity;
    if (wavePosition >= 255) {
        wavePosition = 0;  // Reset the position to maintain the loop
    }

    // Update the hue variable
    hue += 3;
    if (hue >= 255) {
        hue = 0;  // Reset hue to maintain the loop
    }
}

void SpectrumEffect::stop() {
    PDM.end();
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));  // Turn off all LEDs when stopping
}
