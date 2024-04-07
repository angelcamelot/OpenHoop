/**
 * @project OpenHoop
 * @file HulaHoopNeoPixel.h
 * @brief Header file for the HulaHoopNeoPixel class, providing functionality for managing NeoPixels with energy-saving
 * modes.
 * @details This class extends the Adafruit_NeoPixel library to include energy-saving modes and dynamic pixel
 * management.
 * @author github.com/angelcamelot
 * @date 2024-04-07
 * @license Open-source license.
 */

#ifndef OPENHOOP_HULAHOOPNEOPIXEL_H
#define OPENHOOP_HULAHOOPNEOPIXEL_H

#include <Adafruit_NeoPixel.h>

class HulaHoopNeoPixel : public Adafruit_NeoPixel {
private:
    /**
     * @brief Applies energy-saving mode to the specified level.
     */
    void applyEnergySavingMode(uint8_t level);

    uint8_t brightnessLevel; ///< Brightness level of the NeoPixels.
    uint16_t activePixels; ///< Number of active pixels.
    uint16_t energySavingModeLevel; ///< Energy-saving mode level (0-8).

public:
    /**
     * @brief Constructor for the HulaHoopNeoPixel class.
     */
    HulaHoopNeoPixel(uint16_t n, uint8_t p, neoPixelType t = NEO_GRB + NEO_KHZ800);

    /**
     * @brief Override of setPixelColor to apply energy saving mode.
     */
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);

    /**
     * @brief Sets the energy-saving mode level.
     */
    void setEnergySavingMode(uint8_t level);

    /**
     * @brief Gets the number of active pixels.
     */
    uint16_t getActivePixels();
};

#endif //OPENHOOP_HULAHOOPNEOPIXEL_H
