/**
 * @project OpenHoop
 * @file FireEffect.h
 * @brief Header file for the FireEffect class, representing an LED effect simulating a fire.
 * @details Defines the FireEffect class and its methods for starting, updating, and stopping the fire effect.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef FIREEFFECT_H
#define FIREEFFECT_H

#include "Effect.h"

/**
 * @brief Represents an LED effect simulating a fire.
 */
class FireEffect : public Effect {
public:
    /**
     * @brief Constructor for the FireEffect class.
     */
    FireEffect();

    /**
     * @brief Start the fire effect.
     */
    void start() override;

    /**
     * @brief Update the fire effect.
     */
    void update() override;

    /**
     * @brief Stop the fire effect.
     */
    void stop() override;

private:
    int cooling;         ///< Rate of cooling, affecting fading.
    int sparking;        ///< Rate of sparking, affecting intensity variations.
    int numZones;        ///< Number of zones to divide the hoop.
    int* zoneIntensity;  ///< Intensity of each zone.
};

#endif //FIREEFFECT_H
