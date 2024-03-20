/**
 * @project OpenHoop
 * @file LedImage.h
 * @brief Header file for the LedImage class, an abstract base class representing an image composed of LEDs.
 * @details Defines the LedImage class and its methods for setting and getting pixel colors, as well as retrieving the width and height of the image.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_LEDIMAGE_H
#define OPENHOOP_LEDIMAGE_H

#include <Arduino.h>

/**
 * @brief Abstract base class representing an image composed of LEDs.
 */
class LedImage {
private:
    const int width;  ///< Width of the image.
    const int height;  ///< Height of the image.
    uint32_t* pixels;  ///< Array to store pixel colors.

public:
    /**
     * @brief Constructor for the LedImage class.
     * @param w Width of the image.
     * @param h Height of the image.
     */
    LedImage(int w, int h) : width(w), height(h) {
        pixels = new uint32_t[width * height];
    }

    /**
     * @brief Destructor for the LedImage class.
     */
    ~LedImage() {
        delete[] pixels;
    }

    /**
     * @brief Set the color of a pixel at a specific position.
     * @param x X-coordinate of the pixel.
     * @param y Y-coordinate of the pixel.
     * @param color Color to set for the pixel.
     */
    void setPixel(int x, int y, uint32_t color) const {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            pixels[y * width + x] = color;
        }
    }

    /**
     * @brief Get the color of a pixel at a specific position.
     * @param x X-coordinate of the pixel.
     * @param y Y-coordinate of the pixel.
     * @param bkgColor Background color to return if the pixel is out of bounds.
     * @return Color of the specified pixel or background color if out of bounds.
     */
    uint32_t getPixel(int x, int y, uint32_t bkgColor) const {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            return pixels[y * width + x];
        }
        // Return the background color if out of bounds
        return bkgColor;
    }

    /**
     * @brief Get the width of the image.
     * @return Width of the image.
     */
    int getWidth() const {
        return width;
    }

    /**
     * @brief Get the height of the image.
     * @return Height of the image.
     */
    int getHeight() const {
        return height;
    }
};

#endif //OPENHOOP_LEDIMAGE_H
