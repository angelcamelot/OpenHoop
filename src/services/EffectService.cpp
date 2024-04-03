/**
 * @project OpenHoop
 * @file EffectService.cpp
 * @brief Implementation file for the EffectService class, responsible for managing LED effects.
 * @details Implements the methods defined in the EffectService class for setting, updating, and dispatching BLE commands for LED effects.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/services/EffectService.h"
#include "../../include/effects/SolidColorFillEffect.h"
#include "../../include/effects/RainbowEffect.h"
#include "../../include/effects/FireEffect.h"
#include "../../include/effects/PulseEffect.h"
#include "../../include/effects/ColorWaveEffect.h"
#include "../../include/effects/FunkyEffect.h"
#include "../../include/effects/RastafaraiFlagEffect.h"
#include "../../include/effects/SpectrumEffect.h"
#include "../../include/effects/MushroomImageEffect.h"
#include "../../include/effects/RainbowLeopardEffect.h"
#include "../../include/Config.h"

/**
 * @brief Set a new effect, stopping and deleting the current one if it exists.
 */
void EffectService::setEffect(std::unique_ptr<Effect> newEffect) {
    // The unique_ptr will automatically handle the deletion of the currentEffect
    // when it goes out of scope or gets replaced.
    if (currentEffect) {
        currentEffect->stop();
    }

    currentEffect = std::move(newEffect);

    // Start the new effect
    if (currentEffect) {
        currentEffect->start();
    }
}

/**
 * @brief Update the current effect if it exists.
 */
void EffectService::update() const {
    // Update the current effect
    if (currentEffect) {
        currentEffect->update();
    }
}

/**
 * @brief Dispatch an effect command based on the provided gesture.
 * @param gesture The type of effect to dispatch.
 */
void EffectService::dispatchEffectCommand(EffectType gesture) {
    switch (gesture) {
        case EffectType::NO_EFFECT:
            setEffect(std::make_unique<SolidColorFillEffect>(Adafruit_NeoPixel::Color(0, 0, 0)));
            break;
        case EffectType::RAINBOW:
            setEffect(std::make_unique<RainbowEffect>());
            break;
        case EffectType::FIRE:
            setEffect(std::make_unique<FireEffect>());
            break;
        case EffectType::PULSE:
            setEffect(std::make_unique<PulseEffect>());
            break;
        case EffectType::COLORWAVE:
            setEffect(std::make_unique<ColorWaveEffect>());
            break;
        case EffectType::FUNKY:
            setEffect(std::make_unique<FunkyEffect>());
            break;
        case EffectType::RASTAFARAIFLAG:
            setEffect(std::make_unique<RastafaraiFlagEffect>());
            break;
        case EffectType::SPECTRUM:
            setEffect(std::make_unique<SpectrumEffect>());
            break;
        case EffectType::MUSHROOM:
            setEffect(std::make_unique<MushroomImageEffect>());
            break;
        case EffectType::LEOPARDRAINBOW:
            setEffect(std::make_unique<RainbowLeopardEffect>());
        default:
            // Stop the current effect if no matching gesture is found
            setEffect(nullptr);
            break;
    }
}

/**
 * @brief Dispatch a solid color command based on the provided color string.
 * @param colorString The string representing the RGB color code.
 */
void EffectService::dispatchSolidColorCommand(const String& colorString) {
    // Handle potential errors gracefully:
    if (colorString.length() != 6) {
        Serial.println("Invalid color code length (must be 6 characters)");
        setEffect(std::make_unique<SolidColorFillEffect>(Adafruit_NeoPixel::Color(0, 0, 0))); // Set default color in case of error
        return;
    }

    // Extract color components using `strtol` (ensure exceptions are enabled):
    uint8_t red = strtol(colorString.substring(0, 2).c_str(), nullptr, 16);
    uint8_t green = strtol(colorString.substring(2, 4).c_str(), nullptr, 16);
    uint8_t blue = strtol(colorString.substring(4, 6).c_str(), nullptr, 16);

    // Log the extracted RGB values (for debugging purposes):
    Serial.print("Extracted RGB values: ");
    Serial.print("Red: "); Serial.print(red); Serial.print(", ");
    Serial.print("Green: "); Serial.print(green); Serial.print(", ");
    Serial.print("Blue: "); Serial.println(blue);

    // Create and set the solid color effect:
    setEffect(std::make_unique<SolidColorFillEffect>(Adafruit_NeoPixel::Color(red, green, blue)));
}

EffectService::~EffectService() = default;
