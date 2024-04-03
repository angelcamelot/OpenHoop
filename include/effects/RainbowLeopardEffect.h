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
    int hue;                          ///< Hue value for the rainbow effect.
    static constexpr uint8_t maxColorValue = 255; ///< Maximum color value.
};

#endif //OPENHOOP_RAINBOWLEOPARDEFFECT_H
