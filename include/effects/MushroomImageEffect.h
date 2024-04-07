/**
 * @project OpenHoop
 * @file MushroomImageEffect.h
 * @brief Header file for the MushroomImageEffect class.
 * @details Declares the MushroomImageEffect class and its methods for creating a scrolling MushroomImage LED effect.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_MUSHROOMIMAGEEFFECT_H
#define OPENHOOP_MUSHROOMIMAGEEFFECT_H

#include "Effect.h"
#include "../images/MushroomImage.h"

/**
 * @brief Represents a pixel art effect.
 */
class MushroomImageEffect : public Effect {
public:
    explicit MushroomImageEffect();

    /**
     * @brief Start the effect.
     */
    void start() override;

    /**
     * @brief Update the effect.
     */
    void update() override;

    /**
     * @brief Stop the effect.
     */
    void stop() override;

private:
    int positionX = 0; ///< Horizontal position of the image.
    MushroomImage mushroomImage; ///< Instance of the mushroom image.
};
#endif //OPENHOOP_MUSHROOMIMAGEEFFECT_H
