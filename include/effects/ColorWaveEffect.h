/**
 * @project OpenHoop
 * @file ColorWaveEffect.h
 * @brief Header file for the ColorWaveEffect class, representing an LED effect with a color wave pattern.
 * @details Defines the ColorWaveEffect class and its methods for starting, updating, and stopping the color wave effect.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef COLORWAVEEFFECT_H
#define COLORWAVEEFFECT_H

#include "Effect.h"

/**
 * @brief Represents an LED effect with a color wave pattern.
 */
class ColorWaveEffect : public Effect {
public:
    /**
     * @brief Constructor for the ColorWaveEffect class.
     */
    ColorWaveEffect();

    /**
     * @brief Start the color wave effect.
     */
    void start() override;

    /**
     * @brief Update the color wave effect.
     */
    void update() override;

    /**
     * @brief Stop the color wave effect.
     */
    void stop() override;

private:
    int waveSpeed;    ///< Speed of the color wave.
    int hueOffset;    ///< Offset to control the color wave pattern.
    int saturation;   ///< Saturation level of the colors.
    int brightness;   ///< Brightness level of the colors.
};

#endif //COLORWAVEEFFECT_H
