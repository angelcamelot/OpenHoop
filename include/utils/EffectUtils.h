/**
 * @project OpenHoop
 * @file EffectUtils.h
 * @brief Header file for the EffectUtils class, containing utility functions for LED effects.
 * @details Defines static methods for applying brightness, interpolating colors, converting HSV to RGB, mapping values,
 * generating colors based on wheel position, calculating sound spectrum intensity, and managing energy-saving mode.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#ifndef OPENHOOP_EFFECTUTILS_H
#define OPENHOOP_EFFECTUTILS_H

#include <Arduino.h>
#include <PDM.h>

/**
 * @brief LED effect utility functions.
 */
class EffectUtils {
public:
    /**
     * @brief Apply brightness to a color.
     * @param color Original color value.
     * @param brightness Brightness level to be applied.
     * @return Color value with brightness applied.
     */
    static uint32_t applyBrightness(uint32_t color, int brightness);

    /**
     * @brief Interpolate between two colors.
     * @param color1 First color.
     * @param color2 Second color.
     * @param step Current step in the interpolation.
     * @param steps Total number of steps in the interpolation.
     * @return Interpolated color value.
     */
    static uint32_t interpolateColor(uint32_t color1, uint32_t color2, int step, int steps);

    /**
     * @brief Convert HSV to RGB color.
     * @param hue Hue value.
     * @param saturation Saturation value.
     * @param value Brightness value.
     * @return RGB color value.
     */
    static uint32_t HSVtoRGB(int hue, int saturation, int value);

    /**
     * @brief Map a value from one range to another.
     * @param value Value to be mapped.
     * @param fromLow Lower bound of the original range.
     * @param fromHigh Upper bound of the original range.
     * @param toLow Lower bound of the target range.
     * @param toHigh Upper bound of the target range.
     * @return Mapped value in the target range.
     */
    static int mapRange(int value, int fromLow, int fromHigh, int toLow, int toHigh);

    /**
     * @brief Generate color based on wheel position.
     * @param wheelPos Position in the color wheel.
     * @return Color value.
     */
    static uint32_t Wheel(byte wheelPos);

    /**
     * @brief Calculate the sound spectrum intensity.
     * @return Sound spectrum intensity value.
     */
    static int calculateSoundSpectrum();

    /**
     * @brief Set the energy-saving mode.
     * @param mode Energy-saving mode (0 or 1).
     */
    static void setEnergySavingMode(uint8_t mode);

    /**
     * @brief Apply energy-saving mode to a color.
     * @param color Original color value.
     * @return Color value adjusted based on energy-saving mode.
     */
    static uint32_t applyEnergySavingMode(uint32_t color);

private:
    // Buffer to read samples into, each sample is 16-bits
    static short sampleBuffer[256];
    static uint8_t energySavingMode;  ///< Energy-saving mode (0, 1, 2 or 3).

    // Number of samples read
    static volatile int samplesRead;

public:
    /**
     * @brief Callback function for PDM data.
     */
    static void onPDMdata();

    /**
     * @brief Get the inclination angle.
     * @return Inclination angle value.
     */
    static float getInclination();
};

#endif //OPENHOOP_EFFECTUTILS_H
