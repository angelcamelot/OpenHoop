/**
 * @project OpenHoop
 * @file FlowerImage.h
 * @brief Header file for the FlowerImage class, representing an image of a flower.
 * @details Defines the FlowerImage class, a derived class from LedImage.
 * @author github.com/angelcamelot
 * @date 2024-04-02
 * @license Open-source license.
 */

#ifndef OPENHOOP_FLOWERIMAGE_H
#define OPENHOOP_FLOWERIMAGE_H

#include "LedImage.h"

/**
 * @brief Represents an image of a flower for the Hula Hoop LED display.
 */
class FlowerImage : public LedImage {
public:
    /**
     * @brief Constructor for the FlowerImage class.
     */
    explicit FlowerImage(uint32_t color);

private:
    /**
     * @brief Set the colors for the pixel art.
     */
    void setColors(uint32_t color) const;
};

#endif //OPENHOOP_FLOWERIMAGE_H
