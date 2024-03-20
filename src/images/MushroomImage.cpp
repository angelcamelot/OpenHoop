/**
 * @project OpenHoop
 * @file MushroomImage.cpp
 * @brief Source file for the MushroomImage class, representing an image of a mushroom for the Hula Hoop LED display.
 * @details Implements the methods to set colors for the mushroom image.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/images/MushroomImage.h"

MushroomImage::MushroomImage() : LedImage(13, 16) {
    setMushroomColors();
}

void MushroomImage::setMushroomColors() const {
    setPixel(5, 2, 0xFF1C1C);
    setPixel(6, 2, 0xFF1C1C);
    setPixel(6, 9, 0xFF1C1C);
}
