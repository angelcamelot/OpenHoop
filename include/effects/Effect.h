/**
 * @project OpenHoop
 * @file Effect.h
 * @brief Header file for the Effect class, representing an abstract base class for LED effects.
 * @details Defines the Effect class with pure virtual methods for starting, updating, and stopping an LED effect.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_EFFECT_H
#define OPENHOOP_EFFECT_H

/**
 * @brief Abstract base class representing an LED effect.
 */
class Effect {
public:
 /**
  * @brief Start the effect.
  */
 virtual void start() = 0;

 /**
  * @brief Update the effect.
  */
 virtual void update() = 0;

 /**
  * @brief Stop the effect.
  */
 virtual void stop() = 0;

 /**
  * @brief Virtual destructor for the base class.
  */
 virtual ~Effect() = default;
};

#endif //OPENHOOP_EFFECT_H
