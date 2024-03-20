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

MushroomImageEffect::MushroomImageEffect() : currentIndex(0), spaceHeight(5), mushroomHeight(MushroomImage().getHeight()), totalHeight(mushroomHeight + spaceHeight) {}

void MushroomImageEffect::update() {
    auto yOffset = static_cast<signed long>((millis() / 50) % mushroomHeight);

    for (int x = 0; x < hoop.numPixels(); x++) {
        int rowIndex = (x % totalHeight) - spaceHeight;
        if (rowIndex >= 0 && rowIndex < mushroomHeight) {
            uint32_t color = MushroomImage().getPixel(currentIndex, rowIndex + yOffset, 0x8080FF);
            hoop.setPixelColor(x, color);
        } else {
            hoop.setPixelColor(x, 0x8080FF);
        }
    }

    hoop.show();
    currentIndex = (currentIndex + 1) % MushroomImage().getWidth();
}
