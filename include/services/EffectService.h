/**
 * @project OpenHoop
 * @file EffectService.h
 * @brief Header file for the EffectService class, responsible for managing LED effects.
 * @details Defines the EffectService class and its methods for setting, updating, and dispatching BLE commands for LED effects.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_EFFECTSERVICE_H
#define OPENHOOP_EFFECTSERVICE_H

#include <Arduino.h>
#include "../effects/Effect.h"

enum class EffectType {
 NO_EFFECT,
 RAINBOW,
 COLORWAVE,
 FUNKY,
 RASTAFARAIFLAG,
 FIRE,
 MUSHROOM,
 LEOPARDRAINBOW,
 PULSE = 98,
 SPECTRUM = 99,
};

/**
 * @class EffectService
 * @brief Class responsible for managing LED effects.
 */
class EffectService {
private:
 std::unique_ptr<Effect> currentEffect;  ///< Pointer to the current active effect.

public:
 /**
  * @brief Set a new effect.
  * @param newEffect Pointer to the new effect to be set.
  */
 void setEffect(std::unique_ptr<Effect> newEffect);

 /**
  * @brief Update the current effect.
  */
 void update() const;

 /**
  * @brief Dispatch BLE command for changing the LED effect.
  * @param gesture Gesture received through BLE command.
  */
 void dispatchEffectCommand(EffectType gesture);

 /**
  * @brief Dispatch BLE command for setting a solid color.
  * @param colorString String representation of the color received through BLE command.
  */
 void dispatchSolidColorCommand(const String& colorString);

 /**
  * @brief Destructor for the EffectService class.
  */
 ~EffectService();
};

#endif //OPENHOOP_EFFECTSERVICE_H
