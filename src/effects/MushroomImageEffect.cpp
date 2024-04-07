/**
 * @project OpenHoop
 * @file MushroomImageEffect.cpp
 * @brief Implementation file for the MushroomImageEffect class.
 * @details Defines the methods to update the LED display with a scrolling MushroomImage effect.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/MushroomImageEffect.h"
#include "../../include/Config.h"

/**
 * @brief Constructor for MushroomImageEffect.
 */
MushroomImageEffect::MushroomImageEffect() : positionX(0), mushroomImage({255, 0, 0}) {}

/**
 * @brief Initializes the Effect.
 */
void MushroomImageEffect::start() {
    positionX = 0;
}

/**
 * @brief Updates the Pixel Art Effect.
 * Scrolls the pixel art image across the LED display.
 */
void MushroomImageEffect::update() {
    // Constants
    const int ImageWidth = mushroomImage.width;
    const int ImageHeight = mushroomImage.height;

    positionX++;

    if (positionX >= ImageHeight) {
        positionX = 0;
    }

    for (int i = 0; i < hoop.getActivePixels(); i++) {
        int leopardX = positionX; // Use the same X-coordinate for the entire row
        int leopardY = i % ImageWidth; // Adjust hoop index to handle repeat pattern along hoop
        int hoopIndex = i % hoop.getActivePixels(); // Adjust hoop index to handle circular display

        // Get the color from the leopard pattern image
        LedColor mushroomColor = mushroomImage.getPixel(leopardX, leopardY);

        // Check if leopard pattern color is fully transparent
        if (mushroomColor.alpha == 0) {
            // If fully transparent, set the rainbow color
            hoop.setPixelColor(hoopIndex, 100, 100, 100);
        } else {
            // Set the blended color to the hoop
            hoop.setPixelColor(hoopIndex, mushroomColor.red, mushroomColor.green, mushroomColor.blue);
        }
    }
    hoop.show();
    delay(30);
}

/**
 * @brief Stops the Effect.
 * Turns off all LEDs on the display.
 */
void MushroomImageEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}