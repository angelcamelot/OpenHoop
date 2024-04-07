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
#include "../../include/Config.h"

/**
 * @brief Constructor for FireEffect.
 */
FireEffect::FireEffect() : cooling(100), sparking(0), numZones(3), zoneIntensity(new int[numZones]) {}

/**
 * @brief Initializes the Effect.
 */
void FireEffect::start() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}

/**
 * @brief Updates the Effect.
 */
void FireEffect::update() {
    // Initialize zone intensities randomly
    for (int z = 0; z < numZones; z++) {
        zoneIntensity[z] = random(150, 256);  // Adjust the range according to preferences
    }

    // Simulate the fire effect
    for (int i = 0; i < hoop.getActivePixels(); i++) {
        // Cool down each LED
        if (random(256) < cooling) {
            hoop.setPixelColor(i, 0,0,0);
        }

        // Ignite new pixels based on random sparks
        if (random(256) < sparking) {
            int y = random(hoop.getActivePixels());
            int zone = map(y, 0, hoop.getActivePixels(), 0, numZones);  // Map the LED to a zone
            int intensity = zoneIntensity[zone];  // Get the intensity of the zone

            uint8_t r = min(255, random(intensity * 2));  // Generate a random red hue
            uint8_t g = 0;  // Do not use green
            uint8_t b = 0;  // Do not use blue

            hoop.setPixelColor(y, r, g, b);
        }
    }

    hoop.show();
}

/**
 * @brief Stops the Effect.
 * Turns off all LEDs on the display.
 */
void FireEffect::stop() {
    delete[] zoneIntensity;
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
