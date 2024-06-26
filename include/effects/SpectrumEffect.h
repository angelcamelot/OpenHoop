/**
 * @project OpenHoop
 * @file SpectrumEffect.h
 * @brief Header file for the SpectrumEffect class.
 * @details Defines the SpectrumEffect class, responsible for creating a spectrum color effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef SPECTRUMEFFECT_H
#define SPECTRUMEFFECT_H

#include "Effect.h"

/**
 * @brief Represents a spectrum effect.
 */
class SpectrumEffect : public Effect {
public:
    SpectrumEffect();

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
    int hue;  ///< Current hue value for the spectrum effect.
    int wavePosition;  ///< Current position in the wave for dynamic color changes.
};

#endif //SPECTRUMEFFECT_H
