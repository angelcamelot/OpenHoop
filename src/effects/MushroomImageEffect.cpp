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

// NOLINTNEXTLINE
std::mt19937 MushroomImageEffect::randomGenerator;
uint32_t MushroomImageEffect::randomColor;

/**
 * @brief Constructor for the MushroomImageEffect class.
 */
MushroomImageEffect::MushroomImageEffect() : currentIndex(0), spaceHeight(5), mushroomHeight(MushroomImage(0).getHeight()), totalHeight(mushroomHeight + spaceHeight) {
    std::random_device rd;
    randomGenerator.seed(rd());
}

/**
 * @brief Starts the MushroomImage effect.
 */
void MushroomImageEffect::start() {
    // Implementation goes here
}

/**
 * @brief Updates the MushroomImage effect.
 */
void MushroomImageEffect::update() {
    auto yOffset = static_cast<signed long>((millis() / 50) % mushroomHeight);

    for (int x = 0; x < hoop.numPixels(); x++) {
        int rowIndex = (x % totalHeight) - spaceHeight;
        if (rowIndex >= 0 && rowIndex < mushroomHeight) {
            uint32_t color = MushroomImage(randomColor).getPixel(currentIndex, rowIndex + yOffset, 0x8080FF);
            hoop.setPixelColor(x, color);
        } else {
            hoop.setPixelColor(x, 0x8080FF);
        }
    }

    hoop.show();
    currentIndex = (currentIndex + 1) % MushroomImage(0).getWidth();
    randomColor = getRandomColor();
}

/**
 * @brief Stops the MushroomImage effect.
 */
void MushroomImageEffect::stop() {
    // Implementation goes here
}

/**
 * @brief Generates a random color for the MushroomImage effect.
 * @return A randomly selected color.
 */
uint32_t MushroomImageEffect::getRandomColor() {
    const uint32_t mushroomColors[] = {0xFF0000, 0x00FF00, 0xFFFF00, 0x800080, 0xFFD700};
    int numColors = sizeof(mushroomColors) / sizeof(mushroomColors[0]);
    std::uniform_int_distribution<int> distribution(0, numColors - 1);
    int randomIndex = distribution(randomGenerator);
    return mushroomColors[randomIndex];
}
