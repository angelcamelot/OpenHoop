/**
 * @project OpenHoop
 * @file FlowerImage.cpp
 * @brief Source file for the FlowerImage class, representing an image of a flower.
 * @details Implements the methods to set colors for the flower image.
 * @author github.com/angelcamelot
 * @date 2024-04-02
 * @license Open-source license.
 */

#include "../../include/images/FlowerImage.h"

FlowerImage::FlowerImage(LedColor color) : LedImage(12, 18) {
    setColors(color);
}

/**
 * @brief Sets the colors for the flower image.
 * @param color Color to set for the flower.
 */
void FlowerImage::setColors(LedColor color) {
    setPixel(1, 1, {56, 56, 56});
    setPixel(2, 1, {56, 56, 56});
    setPixel(3, 1, {56, 56, 56});
    setPixel(1, 2, {56, 56, 56});
    setPixel(2, 2, {98, 168, 35});
    setPixel(3, 2, {98, 168, 35});
    setPixel(4, 2, {56, 56, 56});
    setPixel(1, 3, {56, 56, 56});
    setPixel(2, 3, {98, 168, 35});
    setPixel(3, 3, {98, 168, 35});
    setPixel(4, 3, {98, 168, 35});
    setPixel(5, 3, {56, 56, 56});
    setPixel(6, 3, {56, 56, 56});
    setPixel(2, 4, {56, 56, 56});
    setPixel(3, 4, {56, 56, 56});
    setPixel(4, 4, {56, 56, 56});
    setPixel(5, 4, color);
    setPixel(6, 4, color);
    setPixel(7, 4, {56, 56, 56});
    setPixel(8, 4, {56, 56, 56});
    setPixel(9, 4, {56, 56, 56});
    setPixel(1, 5, {56, 56, 56});
    setPixel(2, 5, color);
    setPixel(3, 5, color);
    setPixel(4, 5, {56, 56, 56});
    setPixel(5, 5, color);
    setPixel(6, 5, color);
    setPixel(7, 5, {56, 56, 56});
    setPixel(8, 5, color);
    setPixel(9, 5, color);
    setPixel(10, 5, {56, 56, 56});
    setPixel(1, 6, {56, 56, 56});
    setPixel(2, 6, color);
    setPixel(3, 6, color);
    setPixel(4, 6, color);
    setPixel(5, 6, {56, 56, 56});
    setPixel(6, 6, {56, 56, 56});
    setPixel(7, 6, color);
    setPixel(8, 6, color);
    setPixel(9, 6, color);
    setPixel(10, 6, {56, 56, 56});
    setPixel(1, 7, {56, 56, 56});
    setPixel(2, 7, {56, 56, 56});
    setPixel(3, 7, color);
    setPixel(4, 7, {56, 56, 56});
    setPixel(5, 7, {253, 179, 34});
    setPixel(6, 7, {253, 179, 34});
    setPixel(7, 7, {56, 56, 56});
    setPixel(8, 7, color);
    setPixel(9, 7, {56, 56, 56});
    setPixel(10, 7, {56, 56, 56});
    setPixel(0, 8, {56, 56, 56});
    setPixel(1, 8, color);
    setPixel(2, 8, color);
    setPixel(3, 8, {56, 56, 56});
    setPixel(4, 8, {253, 179, 34});
    setPixel(5, 8, {253, 179, 34});
    setPixel(6, 8, {253, 179, 34});
    setPixel(7, 8, {253, 179, 34});
    setPixel(8, 8, {56, 56, 56});
    setPixel(9, 8, color);
    setPixel(10, 8, color);
    setPixel(11, 8, {56, 56, 56});
    setPixel(0, 9, {56, 56, 56});
    setPixel(1, 9, color);
    setPixel(2, 9, color);
    setPixel(3, 9, {56, 56, 56});
    setPixel(4, 9, {253, 179, 34});
    setPixel(5, 9, {253, 179, 34});
    setPixel(6, 9, {253, 179, 34});
    setPixel(7, 9, {253, 179, 34});
    setPixel(8, 9, {56, 56, 56});
    setPixel(9, 9, color);
    setPixel(10, 9, color);
    setPixel(11, 9, {56, 56, 56});
    setPixel(1, 10, {56, 56, 56});
    setPixel(2, 10, {56, 56, 56});
    setPixel(3, 10, color);
    setPixel(4, 10, {56, 56, 56});
    setPixel(5, 10, {253, 179, 34});
    setPixel(6, 10, {253, 179, 34});
    setPixel(7, 10, {56, 56, 56});
    setPixel(8, 10, color);
    setPixel(9, 10, {56, 56, 56});
    setPixel(10, 10, {56, 56, 56});
    setPixel(1, 11, {56, 56, 56});
    setPixel(2, 11, color);
    setPixel(3, 11, color);
    setPixel(4, 11, color);
    setPixel(5, 11, {56, 56, 56});
    setPixel(6, 11, {56, 56, 56});
    setPixel(7, 11, color);
    setPixel(8, 11, color);
    setPixel(9, 11, color);
    setPixel(10, 11, {56, 56, 56});
    setPixel(1, 12, {56, 56, 56});
    setPixel(2, 12, color);
    setPixel(3, 12, color);
    setPixel(4, 12, {56, 56, 56});
    setPixel(5, 12, color);
    setPixel(6, 12, color);
    setPixel(7, 12, {56, 56, 56});
    setPixel(8, 12, color);
    setPixel(9, 12, color);
    setPixel(10, 12, {56, 56, 56});
    setPixel(2, 13, {56, 56, 56});
    setPixel(3, 13, {56, 56, 56});
    setPixel(4, 13, {56, 56, 56});
    setPixel(5, 13, color);
    setPixel(6, 13, color);
    setPixel(7, 13, {56, 56, 56});
    setPixel(8, 13, {56, 56, 56});
    setPixel(9, 13, {56, 56, 56});
    setPixel(5, 14, {56, 56, 56});
    setPixel(6, 14, {56, 56, 56});
    setPixel(7, 14, {98, 168, 35});
    setPixel(8, 14, {98, 168, 35});
    setPixel(9, 14, {98, 168, 35});
    setPixel(10, 14, {56, 56, 56});
    setPixel(7, 15, {56, 56, 56});
    setPixel(8, 15, {98, 168, 35});
    setPixel(9, 15, {98, 168, 35});
    setPixel(10, 15, {56, 56, 56});
    setPixel(8, 16, {56, 56, 56});
    setPixel(9, 16, {56, 56, 56});
    setPixel(10, 16, {56, 56, 56});
}
