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
#include "../../include/utils/EffectUtils.h"
#include <PDM.h>

/**
 * @brief Constructor for SpectrumEffect.
 */
SpectrumEffect::SpectrumEffect() : hue(0), wavePosition(0) {}

/**
 * @brief Initializes the Effect.
 */
void SpectrumEffect::start() {
    PDM.begin(1, 16000);
}

/**
 * @brief Updates the Effect.
 */
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
    int activePixels = EffectUtils::mapRange(soundIntensity, 1, 10, 1, hoop.getActivePixels());

    // Apply the inverted background color to all LEDs
    for (int i = 0; i < hoop.getActivePixels(); i++) {
        uint8_t r = (invertedBackgroundColor >> 16) & 0xFF;
        uint8_t g = (invertedBackgroundColor >> 8) & 0xFF;
        uint8_t b = invertedBackgroundColor & 0xFF;
        hoop.setPixelColor(i, r, g, b);
    }

    // Apply the wave color to the active pixels
    for (int i = 0; i < activePixels; i++) {
        uint8_t r = (waveColor >> 16) & 0xFF;
        uint8_t g = (waveColor >> 8) & 0xFF;
        uint8_t b = waveColor & 0xFF;
        hoop.setPixelColor(i, r, g, b);
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

/**
 * @brief Stops the Effect.
 * Turns off all LEDs on the display.
 */
void SpectrumEffect::stop() {
    PDM.end();
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
