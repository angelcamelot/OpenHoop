/**
 * @project OpenHoop
 * @file CupcakeImage.h
 * @brief Header file for the CupcakeImage class, representing an image of a cupcake.
 * @details Defines the CupcakeImage class, a derived class from LedImage.
 * @author github.com/angelcamelot
 * @date 2024-04-02
 * @license Open-source license.
 */

#ifndef OPENHOOP_CUPCAKEIMAGE_H
#define OPENHOOP_CUPCAKEIMAGE_H

#include "LedImage.h"

/**
 * @brief Represents an image of a cupcake for the Hula Hoop LED display.
 */
class CupcakeImage : public LedImage {
public:
    /**
     * @brief Constructor for the CupcakeImage class.
     */
    explicit CupcakeImage(LedColor color);

private:
    /**
     * @brief Set the colors for the pixel art.
     */
    void setColors(LedColor color);
};

#endif //OPENHOOP_CUPCAKEIMAGE_H
