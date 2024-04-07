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

MushroomImage::MushroomImage(LedColor color) : LedImage(13, 16) {
    setMushroomColors(color);
}

/**
 * @brief Sets the colors for the mushroom image.
 * @param color Color to set for the mushroom.
 */
void MushroomImage::setMushroomColors(LedColor color) {
    setPixel(4, 0, {0, 0, 0});
    setPixel(5, 0, {0, 0, 0});
    setPixel(6, 0, {0, 0, 0});
    setPixel(7, 0, {0, 0, 0});
    setPixel(8, 0, {0, 0, 0});
    setPixel(9, 0, {0, 0, 0});
    setPixel(10, 0, {0, 0, 0});
    setPixel(3, 1, {0, 0, 0});
    setPixel(4, 1, {0, 0, 0});
    setPixel(5, 1, color);
    setPixel(6, 1, color);
    setPixel(7, 1, color);
    setPixel(8, 1, color);
    setPixel(11, 1, {0, 0, 0});
    setPixel(12, 1, {0, 0, 0});
    setPixel(2, 2, {0, 0, 0});
    setPixel(5, 2, color);
    setPixel(6, 2, color);
    setPixel(7, 2, color);
    setPixel(8, 2, color);
    setPixel(13, 2, {0, 0, 0});
    setPixel(1, 3, {0, 0, 0});
    setPixel(4, 3, color);
    setPixel(5, 3, color);
    setPixel(6, 3, color);
    setPixel(7, 3, color);
    setPixel(8, 3, color);
    setPixel(9, 3, color);
    setPixel(14, 3, {0, 0, 0});
    setPixel(1, 4, {0, 0, 0});
    setPixel(3, 4, color);
    setPixel(4, 4, color);
    setPixel(8, 4, color);
    setPixel(9, 4, color);
    setPixel(10, 4, color);
    setPixel(14, 4, {0, 0, 0});
    setPixel(0, 5, {0, 0, 0});
    setPixel(1, 5, color);
    setPixel(2, 5, color);
    setPixel(3, 5, color);
    setPixel(9, 5, color);
    setPixel(10, 5, color);
    setPixel(11, 5, color);
    setPixel(12, 5, color);
    setPixel(13, 5, color);
    setPixel(14, 5, color);
    setPixel(15, 5, {0, 0, 0});
    setPixel(0, 6, {0, 0, 0});
    setPixel(1, 6, color);
    setPixel(2, 6, color);
    setPixel(3, 6, color);
    setPixel(9, 6, color);
    setPixel(10, 6, color);
    setPixel(11, 6, color);
    setPixel(14, 6, color);
    setPixel(15, 6, {0, 0, 0});
    setPixel(0, 7, {0, 0, 0});
    setPixel(2, 7, color);
    setPixel(3, 7, color);
    setPixel(9, 7, color);
    setPixel(10, 7, color);
    setPixel(15, 7, {0, 0, 0});
    setPixel(0, 8, {0, 0, 0});
    setPixel(3, 8, color);
    setPixel(4, 8, color);
    setPixel(8, 8, color);
    setPixel(9, 8, color);
    setPixel(10, 8, color);
    setPixel(15, 8, {0, 0, 0});
    setPixel(0, 9, {0, 0, 0});
    setPixel(3, 9, color);
    setPixel(4, 9, color);
    setPixel(5, 9, color);
    setPixel(6, 9, color);
    setPixel(7, 9, color);
    setPixel(8, 9, color);
    setPixel(9, 9, color);
    setPixel(10, 9, color);
    setPixel(11, 9, color);
    setPixel(14, 9, color);
    setPixel(15, 9, {0, 0, 0});
    setPixel(0, 10, {0, 0, 0});
    setPixel(2, 10, color);
    setPixel(3, 10, color);
    setPixel(4, 10, {0, 0, 0});
    setPixel(5, 10, {0, 0, 0});
    setPixel(6, 10, {0, 0, 0});
    setPixel(7, 10, {0, 0, 0});
    setPixel(8, 10, {0, 0, 0});
    setPixel(9, 10, {0, 0, 0});
    setPixel(10, 10, {0, 0, 0});
    setPixel(11, 10, {0, 0, 0});
    setPixel(12, 10, color);
    setPixel(13, 10, color);
    setPixel(14, 10, color);
    setPixel(15, 10, {0, 0, 0});
    setPixel(1, 11, {0, 0, 0});
    setPixel(2, 11, {0, 0, 0});
    setPixel(3, 11, {0, 0, 0});
    setPixel(4, 11, {254, 213, 171});
    setPixel(5, 11, {254, 213, 171});
    setPixel(6, 11, {0, 0, 0});
    setPixel(7, 11, {254, 213, 171});
    setPixel(8, 11, {254, 213, 171});
    setPixel(9, 11, {0, 0, 0});
    setPixel(10, 11, {254, 213, 171});
    setPixel(11, 11, {254, 213, 171});
    setPixel(12, 11, {0, 0, 0});
    setPixel(13, 11, {0, 0, 0});
    setPixel(14, 11, {0, 0, 0});
    setPixel(2, 12, {0, 0, 0});
    setPixel(3, 12, {254, 213, 171});
    setPixel(4, 12, {254, 213, 171});
    setPixel(5, 12, {254, 213, 171});
    setPixel(6, 12, {0, 0, 0});
    setPixel(7, 12, {254, 213, 171});
    setPixel(8, 12, {254, 213, 171});
    setPixel(9, 12, {0, 0, 0});
    setPixel(10, 12, {254, 213, 171});
    setPixel(11, 12, {254, 213, 171});
    setPixel(12, 12, {254, 213, 171});
    setPixel(13, 12, {0, 0, 0});
    setPixel(2, 13, {0, 0, 0});
    setPixel(3, 13, {254, 213, 171});
    setPixel(4, 13, {254, 213, 171});
    setPixel(5, 13, {254, 213, 171});
    setPixel(6, 13, {254, 213, 171});
    setPixel(7, 13, {254, 213, 171});
    setPixel(8, 13, {254, 213, 171});
    setPixel(9, 13, {254, 213, 171});
    setPixel(10, 13, {254, 213, 171});
    setPixel(11, 13, {254, 213, 171});
    setPixel(12, 13, {254, 213, 171});
    setPixel(13, 13, {0, 0, 0});
    setPixel(3, 14, {0, 0, 0});
    setPixel(4, 14, {254, 213, 171});
    setPixel(5, 14, {254, 213, 171});
    setPixel(6, 14, {254, 213, 171});
    setPixel(7, 14, {254, 213, 171});
    setPixel(8, 14, {254, 213, 171});
    setPixel(9, 14, {254, 213, 171});
    setPixel(10, 14, {254, 213, 171});
    setPixel(11, 14, {254, 213, 171});
    setPixel(12, 14, {0, 0, 0});
    setPixel(4, 15, {0, 0, 0});
    setPixel(5, 15, {0, 0, 0});
    setPixel(6, 15, {0, 0, 0});
    setPixel(7, 15, {0, 0, 0});
    setPixel(8, 15, {0, 0, 0});
    setPixel(9, 15, {0, 0, 0});
    setPixel(10, 15, {0, 0, 0});
    setPixel(11, 15, {0, 0, 0});
}
