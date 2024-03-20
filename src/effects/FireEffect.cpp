/**
 * @project OpenHoop
 * @file FireEffect.cpp
 * @brief Implementation file for the FireEffect class, representing an LED effect simulating a fire.
 * @details Defines the methods to start, update, and stop the fire effect.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/FireEffect.h"
#include "../../include/utils/EffectUtils.h"
#include "../../include/Config.h"

FireEffect::FireEffect() : cooling(100), sparking(0), numZones(3), zoneIntensity(new int[numZones]) {}

void FireEffect::start() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}

void FireEffect::update() {
    // Initialize zone intensities randomly
    for (int z = 0; z < numZones; z++) {
        zoneIntensity[z] = random(150, 256);  // Adjust the range according to preferences
    }

    // Simulate the fire effect
    for (int i = 0; i < hoop.numPixels(); i++) {
        // Cool down each LED
        if (random(256) < cooling) {
            hoop.setPixelColor(i, Adafruit_NeoPixel::Color(0, 0, 0));
        }

        // Ignite new pixels based on random sparks
        if (random(256) < sparking) {
            int y = random(hoop.numPixels());
            int zone = map(y, 0, hoop.numPixels(), 0, numZones);  // Map the LED to a zone
            int intensity = zoneIntensity[zone];  // Get the intensity of the zone

            int r = min(255, random(intensity * 2));  // Generate a random red hue
            int g = 0;  // Do not use green
            int b = 0;  // Do not use blue

            hoop.setPixelColor(y, EffectUtils::applyEnergySavingMode(Adafruit_NeoPixel::Color(r, g, b)));
        }
    }

    hoop.show();
}

void FireEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
    delete[] zoneIntensity;
}
