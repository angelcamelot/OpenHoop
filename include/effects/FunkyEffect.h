/**
 * @project OpenHoop
 * @file FunkyEffect.h
 * @brief Header file for the FunkyEffect class.
 * @details Declares the FunkyEffect class and its methods for creating a dynamic and colorful LED effect.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef FUNKYEFFECT_H
#define FUNKYEFFECT_H

#include "Effect.h"
#include "../utils/EffectUtils.h"

class FunkyEffect : public Effect {
public:
    FunkyEffect();

    void start() override;
    void update() override;
    void stop() override;

private:
    int time;
    uint32_t colors[5]{};
};

#endif // FUNKYEFFECT_H
