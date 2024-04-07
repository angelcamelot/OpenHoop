/**
 * @project OpenHoop
 * @file LeopardPrintImage.h
 * @brief Header file for the LeopardPrintImage class, representing an image of a Leopard print pattern.
 * @details Defines the LeopardPrintImage class, a derived class from LedImage.
 * @author github.com/angelcamelot
 * @date 2024-04-02
 * @license Open-source license.
 */

#ifndef OPENHOOP_LEOPARDPRINTIMAGE_H
#define OPENHOOP_LEOPARDPRINTIMAGE_H

#include "LedImage.h"

/**
 * @brief Represents an image of a leopard print pattern for the Hula Hoop LED display.
 */
class LeopardPrintImage : public LedImage {
public:
    /**
     * @brief Constructor for the LeopardPrintImage class.
     */
    explicit LeopardPrintImage(LedColor primary_color, LedColor secondary_color);

private:
    /**
     * @brief Set the colors for the leopard print pattern.
     */
    void setPatternColors(LedColor primary_color, LedColor secondary_color);
};

#endif //OPENHOOP_LEOPARDPRINTIMAGE_H
