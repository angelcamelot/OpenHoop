/**
 * @project OpenHoop
 * @file SolidColorFillEffect.h
 * @brief Header file for the SolidColorFillEffect class.
 * @details Defines the SolidColorFillEffect class, responsible for creating a solid color fill effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_SOLIDCOLORFILLEFFECT_H
#define OPENHOOP_SOLIDCOLORFILLEFFECT_H

#include "Arduino.h"
#include "Effect.h"

class SolidColorFillEffect : public Effect {
public:
    /**
     * @brief Constructor for SolidColorFillEffect.
     * @param color Solid color to fill the LEDs with.
     */
    explicit SolidColorFillEffect(uint32_t color);

    void start() override;
    void update() override;
    void stop() override;

private:
    const uint32_t solidColor;  ///< Solid color for the fill effect.
};

#endif //OPENHOOP_SOLIDCOLORFILLEFFECT_H
