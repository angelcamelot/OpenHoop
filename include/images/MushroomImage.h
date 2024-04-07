/**
 * @project OpenHoop
 * @file MushroomImage.h
 * @brief Header file for the MushroomImage class, representing an image of a mushroom for the Hula Hoop LED display.
 * @details Defines the MushroomImage class, a derived class from LedImage, and its methods for setting mushroom colors.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_MUSHROOMIMAGE_H
#define OPENHOOP_MUSHROOMIMAGE_H

#include "LedImage.h"

/**
 * @brief Represents an image of a mushroom for the Hula Hoop LED display.
 */
class MushroomImage : public LedImage {
public:
    /**
     * @brief Constructor for the MushroomImage class.
     */
    explicit MushroomImage(LedColor color);

private:
    /**
     * @brief Set the colors for the mushroom image.
     */
    void setMushroomColors(LedColor color);
};

#endif //OPENHOOP_MUSHROOMIMAGE_H
