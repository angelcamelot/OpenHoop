/**
 * @project OpenHoop
 * @file RainbowLeopardEffect.h
 * @brief Header file for the RainbowLeopardEffect class.
 * @details Defines the RainbowLeopardEffect class, responsible for creating a rainbow leopard effect on the HulaHoop.
 * @author github.com/angelcamelot
 * @date 2024-04-02
 * @license Open-source license.
 */

#ifndef OPENHOOP_RAINBOWLEOPARDEFFECT_H
#define OPENHOOP_RAINBOWLEOPARDEFFECT_H

#include "Effect.h"
#include "../images/LeopardPrintImage.h"
#include "Arduino.h"

/**
 * @brief Represents a rainbow leopard animal print LED effect.
 */
class RainbowLeopardEffect : public Effect {
public:
    RainbowLeopardEffect();

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

private:
    int positionX = 0; ///< Horizontal position of the leopard pattern.
    LeopardPrintImage leopardImage; ///< Instance of leopard print pattern image.
};

#endif //OPENHOOP_RAINBOWLEOPARDEFFECT_H
