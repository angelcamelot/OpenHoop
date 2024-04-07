/**
 * @project OpenHoop
 * @file RainbowLeopardEffect.cpp
 * @brief Implementation file for the RainbowLeopardEffect class.
 * @details Defines the methods for the RainbowLeopardEffect class, responsible for creating a rainbow leopard print
 * effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/RainbowLeopardEffect.h"
#include "../../include/utils/EffectUtils.h"
#include "../../include/Config.h"

/**
 * @brief Constructor for RainbowLeopardEffect.
 */
RainbowLeopardEffect::RainbowLeopardEffect() : positionX(0), leopardImage({0, 0, 100}, {0, 100, 0}) {}

/**
 * @brief Initializes the Effect.
 */
void RainbowLeopardEffect::start() {
    positionX = 0;
}

/**
 * @brief Updates the Pixel Art Effect.
 * Scrolls the pixel art image across the LED display.
 */
void RainbowLeopardEffect::update() {
    // Constants
    const int leopardWidth = leopardImage.width;
    const int leopardHeight = leopardImage.height;
    const int maxHueValue = 125;

    // Calculate the X position for the leopard pattern
    positionX++;

    // Reset X position if it exceeds the width of the leopard pattern
    if (positionX >= leopardHeight) {
        positionX = 0;
    }

    // Render the rainbow leopard pattern on the hoop
    for (int i = 0; i < hoop.getActivePixels(); i++) {
        int leopardX = positionX; // Use the same X-coordinate for the entire row
        int leopardY = i % leopardWidth; // Adjust hoop index to handle repeat pattern along hoop
        int hoopIndex = i % hoop.getActivePixels(); // Adjust hoop index to handle circular display

        // Get the color from the leopard pattern image
        LedColor leopardColor = leopardImage.getPixel(leopardX, leopardY);

        // Apply rainbow effect to the leopard pattern color
        uint32_t rainbowLeopardColor = EffectUtils::Wheel((i) % maxHueValue);
        uint8_t rainbowLeopardR = (rainbowLeopardColor >> 16) & 0xFF;
        uint8_t rainbowLeopardG = (rainbowLeopardColor >> 8) & 0xFF;
        uint8_t rainbowLeopardB = rainbowLeopardColor & 0xFF;

        // Check if leopard pattern color is fully transparent
        if (leopardColor.alpha == 0) {
            // If fully transparent, set the rainbow color
            hoop.setPixelColor(hoopIndex, rainbowLeopardR, rainbowLeopardG, rainbowLeopardB);
        } else {
            // Set the blended color to the hoop
            hoop.setPixelColor(hoopIndex, leopardColor.red, leopardColor.green, leopardColor.blue);
        }
    }

    // Update the hoop display
    hoop.show();
    delay(60);
}

/**
 * @brief Stops the Effect.
 * Turns off all LEDs on the display.
 */
void RainbowLeopardEffect::stop() {
    hoop.fill(Adafruit_NeoPixel::Color(0, 0, 0));
}
