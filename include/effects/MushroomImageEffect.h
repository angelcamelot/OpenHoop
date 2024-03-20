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

class MushroomImageEffect : public Effect {
public:
    explicit MushroomImageEffect();

    void update() override;

private:
    int currentIndex;
    const int spaceHeight;
    const int mushroomHeight;
    const int totalHeight;
};

#endif //OPENHOOP_MUSHROOMIMAGEEFFECT_H
