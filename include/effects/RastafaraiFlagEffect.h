/**
 * @project OpenHoop
 * @file RastafaraiFlagEffect.h
 * @brief Header file for the RastafaraiFlagEffect class.
 * @details Defines the RastafaraiFlagEffect class, responsible for creating a Rastafarian flag-inspired color effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef RASTAFARAIFLAGEFFECT_H
#define RASTAFARAIFLAGEFFECT_H

#include "Effect.h"
#include "../Config.h"

/**
 * @brief Represents a rastafarai colors flag effect.
 */
class RastafaraiFlagEffect : public Effect {
public:
    RastafaraiFlagEffect();

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
    float angle;  ///< Current angle of the effect.
    float angularSpeed;  ///< Speed of rotation for the flag colors.
    float colorOffset;  ///< Offset to adjust the color palette.
    uint32_t color1, color2, color3;  ///< Colors representing the Rastafarian flag.
    int numLeds;  ///< Number of LEDs in the hoop.
};

#endif //RASTAFARAIFLAGEFFECT_H
