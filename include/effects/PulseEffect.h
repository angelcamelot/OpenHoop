/**
 * @project OpenHoop
 * @file PulseEffect.h
 * @brief Header file for the PulseEffect class.
 * @details Defines the PulseEffect class, responsible for creating a pulsating color effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef PULSEEFFECT_H
#define PULSEEFFECT_H

#include "Effect.h"
#include <Arduino.h>

/**
 * @brief Represents an LED pulse effect.
 */
class PulseEffect : public Effect {
public:
    PulseEffect();

    /**
     * @brief Start the pulse effect.
     */
    void start() override;

    /**
     * @brief Update the pulse effect.
     */
    void update() override;

    /**
     * @brief Stop the pulse effect.
     */
    void stop() override;

private:
    int pulseSpeed;          ///< Speed of the pulse effect.
    int pulseBrightness;     ///< Maximum brightness of the pulse.
    int pulseIncrement;      ///< Increment value to dynamically adjust brightness.
    int currentColorIndex;   ///< Index to select the current color from the palette.
    uint32_t colors[5]{};    ///< Array to store the color palette.
};

#endif //PULSEEFFECT_H
