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

/**
 * @brief Struct representing a color with red, green, blue, and alpha (transparency) components.
 */
struct LedColor {
    int red;        ///< Red component of the color.
    int green;      ///< Green component of the color.
    int blue;       ///< Blue component of the color.
    int alpha;      ///< Alpha (transparency) component of the color (0 for fully transparent, 255 for opaque).

    // Default constructor initializes to a fully transparent color
    LedColor() : red(0), green(0), blue(0), alpha(0) {}

    /**
     * @brief Constructor for LedColor struct.
     * @param r Red component.
     * @param g Green component.
     * @param b Blue component.
     * @param a Alpha (transparency) component (0 for fully transparent, 255 for opaque).
     */
    LedColor(int r, int g, int b, int a = 255) : red(r), green(g), blue(b), alpha(a) {}
};

/**
 * @brief Abstract base class representing an image composed of LEDs.
 */
class LedImage {
protected:
    LedColor* pixels;       ///< Array to store pixel colors.

public:
    const int width;        ///< Width of the image.
    const int height;       ///< Height of the image.
    /**
     * @brief Constructor for the LedImage class.
     * @param w Width of the image.
     * @param h Height of the image.
     */
    LedImage(int w, int h);

    /**
     * @brief Destructor for the LedImage class.
     */
    ~LedImage();

    /**
     * @brief Set the color of a pixel at a specific position.
     * @param x X-coordinate of the pixel.
     * @param y Y-coordinate of the pixel.
     * @param color Color to set for the pixel.
     */
    void setPixel(int x, int y, const LedColor& color);

    /**
     * @brief Get the color of a pixel at a specific position.
     * @param x X-coordinate of the pixel.
     * @param y Y-coordinate of the pixel.
     * @return Color of the specified pixel or background color if out of bounds.
     */
    LedColor getPixel(int x, int y) const;

    /**
     * @brief Check if the given coordinates are valid.
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @return True if the coordinates are valid, false otherwise.
     */
    bool isValidIndex(int x, int y) const;
};

#endif // OPENHOOP_LEDIMAGE_H
