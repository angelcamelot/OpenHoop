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
#include "Arduino.h"
#include <random>

class MushroomImageEffect : public Effect {
public:
    explicit MushroomImageEffect();

    /**
     * @brief Start the rainbow effect.
     */
    void start() override;

    /**
     * @brief Update the rainbow effect.
     */
    void update() override;

    /**
     * @brief Stop the rainbow effect.
     */
    void stop() override;

    static uint32_t getRandomColor();

private:
    int currentIndex; ///< Current index for scrolling the MushroomImage.
    const int spaceHeight; ///< Space height between MushroomImages.
    const int mushroomHeight; ///< Height of a MushroomImage.
    const int totalHeight; ///< Total height considering space and MushroomImage height.
    static std::mt19937 randomGenerator; ///< Random number generator for color selection.
    static uint32_t randomColor; ///< Random color for MushroomImage.
};

#endif //OPENHOOP_MUSHROOMIMAGEEFFECT_H
