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
#include "../utils/EffectUtils.h"

class SpectrumEffect : public Effect {
public:
    SpectrumEffect();

    void start() override;
    void update() override;
    void stop() override;

private:
    int hue;  ///< Current hue value for the spectrum effect.
    int wavePosition;  ///< Current position in the wave for dynamic color changes.
};

#endif //SPECTRUMEFFECT_H
