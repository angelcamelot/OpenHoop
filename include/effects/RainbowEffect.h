/**
 * @project OpenHoop
 * @file RainbowEffect.h
 * @brief Header file for the RainbowEffect class.
 * @details Defines the RainbowEffect class, responsible for creating a rainbow color effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_RAINBOWEFFECT_H
#define OPENHOOP_RAINBOWEFFECT_H

#include "Effect.h"
#include "Arduino.h"

/**
 * @brief Represents a rainbow LED effect.
 */
class RainbowEffect : public Effect {
public:
    RainbowEffect();

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
    int hue;  ///< Hue value for the rainbow effect.
    static constexpr uint8_t maxColorValue = 255; ///< Maximum color value.
};

#endif //OPENHOOP_RAINBOWEFFECT_H
