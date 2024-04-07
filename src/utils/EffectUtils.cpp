/**
* @project OpenHoop
 * @file EffectUtils.cpp
 * @brief Source file for the EffectUtils class, containing utility functions for LED effects.
 * @details Implements static methods for applying brightness, interpolating colors, converting HSV to RGB, mapping values,
 *          generating colors based on wheel position, calculating sound spectrum intensity, and managing energy-saving mode.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/utils/EffectUtils.h"
#include "../../include/Config.h"
#include "Arduino_BMI270_BMM150.h"

/**
 * @brief Interpolate color between two given colors.
 */
uint32_t EffectUtils::interpolateColor(uint32_t color1, uint32_t color2, int step, int steps) {
    uint8_t r = map(step, 0, steps, static_cast<uint8_t>((color1 >> 16) & 0xFF), static_cast<uint8_t>((color2 >> 16) & 0xFF));
    uint8_t g = map(step, 0, steps, static_cast<uint8_t>((color1 >> 8) & 0xFF), static_cast<uint8_t>((color2 >> 8) & 0xFF));
    uint8_t b = map(step, 0, steps, static_cast<uint8_t>(color1 & 0xFF), static_cast<uint8_t>(color2 & 0xFF));
    return Adafruit_NeoPixel::Color(r, g, b);
}

/**
 * @brief Convert HSV color to RGB.
 */
uint32_t EffectUtils::HSVtoRGB(int hue, int saturation, int value) {
    int chroma = (value * saturation) / 255;
    int h = hue / 43; // sector 0 to 5
    int x = chroma * (1 - abs((h % 2) - 1));
    int r, g, b;

    switch (h) {
        case 0: r = chroma; g = x; b = 0; break;
        case 1: r = x; g = chroma; b = 0; break;
        case 2: r = 0; g = chroma; b = x; break;
        case 3: r = 0; g = x; b = chroma; break;
        case 4: r = x; g = 0; b = chroma; break;
        default: r = chroma; g = 0; b = x; break;
    }

    int m = value - chroma;
    r += m; g += m; b += m;

    return (static_cast<uint32_t>(r) << 16) | (static_cast<uint32_t>(g) << 8) | static_cast<uint32_t>(b);
}

/**
 * @brief Map a value from one range to another.
 */
int EffectUtils::mapRange(int value, int fromLow, int fromHigh, int toLow, int toHigh) {
    return map(constrain(value, fromLow, fromHigh), fromLow, fromHigh, toLow, toHigh);
}

/**
 * @brief Generate color based on wheel position for the rainbow effect.
 */
uint32_t EffectUtils::Wheel(byte wheelPos) {
    wheelPos = 255 - wheelPos;
    if (wheelPos < 85) {
        return ((255 - wheelPos * 3) << 16) | (wheelPos * 3);
    } else if (wheelPos < 170) {
        wheelPos -= 85;
        return (wheelPos * 3) | ((255 - wheelPos * 3) << 8);
    } else {
        wheelPos -= 170;
        return ((wheelPos * 3) << 16) | (255 - wheelPos * 3);
    }
}

/**
 * @brief Apply brightness to a given color.
 */
uint32_t EffectUtils::applyBrightness(uint32_t color, int brightness) {
    uint8_t r = (color >> 16) & 0xFF;
    uint8_t g = (color >> 8) & 0xFF;
    uint8_t b = color & 0xFF;

    r = (r * brightness) / 255;
    g = (g * brightness) / 255;
    b = (b * brightness) / 255;

    return Adafruit_NeoPixel::Color(r, g, b);
}

/**
 * @brief Static array to store audio sample data.
 */
short EffectUtils::sampleBuffer[256];

/**
 * @brief Static variable to track the number of samples read.
 */
volatile int EffectUtils::samplesRead;

/**
 * @brief Callback function for PDM data.
 * Reads PDM data into the sample buffer.
 */
void EffectUtils::onPDMdata() {
    // Query the number of bytes available
    int bytesAvailable = PDM.available();

    // Read into the sample buffer
    PDM.read(sampleBuffer, bytesAvailable);

    // 16-bit, 2 bytes per sample
    samplesRead = bytesAvailable / 2;
}

/**
 * @brief Calculate the sound spectrum intensity.
 * @return The calculated sound intensity.
 */
int EffectUtils::calculateSoundSpectrum() {
    // Wait for samples to be read
    if (samplesRead) {
        Serial.print("Samples Read: ");
        Serial.println(samplesRead);

        int soundIntensity = 0;

        // Calculate the average intensity of the sound spectrum
        for (int i = 0; i < samplesRead; i++) {
            soundIntensity += abs(sampleBuffer[i]);
        }

        // Clear the read count
        samplesRead = 0;

        Serial.print("Total Sound Intensity: ");
        Serial.println(soundIntensity);

        // Map the sound intensity to a value between 1 and 10
        int mappedIntensity = mapRange(soundIntensity, 9999, 29999, 1, 10);

        Serial.print("Mapped Sound Intensity: ");
        Serial.println(mappedIntensity);

        return mappedIntensity;
    }

    Serial.println("No Samples Read");
    return 0;  // Return 0 if no samples are read
}

/**
 * @brief Get the inclination angle based on gyroscope readings.
 * @return The inclination angle.
 */
float EffectUtils::getInclination() {
    float x, y, z;
    // Read gyroscope values
    IMU.readGyroscope(x, y, z);

    // Calculate inclination on the X and Y axes
    auto inclinationX = static_cast<float>(atan2(y, z) * RAD_TO_DEG);
    auto inclinationY = static_cast<float>(atan2(-x, sqrt(y * y + z * z)) * RAD_TO_DEG);

    // Ensure inclination is in the range [0, 360)
    inclinationX = static_cast<float>(fmod(inclinationX + 360, 360));
    inclinationY = static_cast<float>(fmod(inclinationY + 360, 360));

    // Average of inclinations on X and Y
    auto inclination = static_cast<float>((inclinationX + inclinationY) / 2.0);

    return inclination;
}
