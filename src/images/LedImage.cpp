/**
 * @project OpenHoop
 * @file LedImage.cpp
 * @brief Source file for the LedImage class, an abstract base class representing an image composed of LEDs.
 * @details Implements the methods to set and get pixel colors, as well as checking the validity of pixel coordinates.
 * @author github.com/angelcamelot
 * @date 2024-04-07
 * @license Open-source license.
 */

#include "../../include/images/LedImage.h"
#include <algorithm> // For std::fill

/**
 * @brief Constructor for the LedImage class.
 * @param w Width of the image.
 * @param h Height of the image.
 */
LedImage::LedImage(int w, int h) : width(w), height(h) {
    // Initialize the pixel array with a fully transparent color
    pixels = new LedColor[width * height];
    std::fill(pixels, pixels + (width * height), LedColor(0, 0, 0, 0));
}

/**
 * @brief Destructor for the LedImage class.
 */
LedImage::~LedImage() {
    delete[] pixels;
}

/**
 * @brief Set the color of a pixel at a specific position.
 * @param x X-coordinate of the pixel.
 * @param y Y-coordinate of the pixel.
 * @param color Color to set.
 */
void LedImage::setPixel(int x, int y, const LedColor& color) {
    if (isValidIndex(x, y)) {
        pixels[y * width + x] = color;
    }
}

/**
 * @brief Get the color of a pixel at a specific position.
 * @param x X-coordinate of the pixel.
 * @param y Y-coordinate of the pixel.
 * @return Color of the pixel.
 */
LedColor LedImage::getPixel(int x, const int y) const {
    if (isValidIndex(x, y)) {
        return pixels[y * width + x];
    }
    return {0, 0, 0, 0}; // Return fully transparent color for out-of-bounds pixels
}

/**
 * @brief Check if the given coordinates are valid.
 * @param x X-coordinate.
 * @param y Y-coordinate.
 * @return True if the coordinates are valid, false otherwise.
 */
bool LedImage::isValidIndex(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}
