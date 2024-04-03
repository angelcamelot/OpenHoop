/**
 * @project OpenHoop
 * @file RainbowLeopardEffect.cpp
 * @brief Implementation file for the RainbowLeopardEffect class.
 * @details Defines the methods for the RainbowLeopardEffect class, responsible for creating a rainbow leopard print
 * effect on the LED display.
 * @author github.com/angelcamelot
 * @date 2024-03-17
 * @license Open-source license.
 */

#include "../../include/effects/RainbowLeopardEffect.h"
#include "../../include/utils/EffectUtils.h"
#include "../../include/Config.h"

/**
 * @brief Constructor for the RainbowLeopardEffect class.
 */
RainbowLeopardEffect::RainbowLeopardEffect() : hue(0) {}

/**
 * @brief Starts the rainbow leopard effect.
 */
void RainbowLeopardEffect::start() {
    // Implementation goes here
}

/**
 * @brief Updates the rainbow leopard effect.
 */
void RainbowLeopardEffect::update() {
    static constexpr uint8_t maxHueValue = 255;
    static uint16_t i = 0;

    for (int x = 0; x < hoop.numPixels(); x++) {
        int leopardX = x % 30;
        int rowIndex = x / 30;

        uint32_t rainbowColor = EffectUtils::applyEnergySavingMode(EffectUtils::Wheel((i + x) % maxHueValue));
        uint8_t r = ((rainbowColor >> 16) & 0xFF);
        uint8_t g = ((rainbowColor >> 8) & 0xFF);
        uint8_t b = (rainbowColor & 0xFF);

        uint32_t leopardColor = LeopardPrintImage(0x000000, 0x808080).getPixel(leopardX, rowIndex, rainbowColor);

        uint8_t leopardOpacity = 153;
        r = ((r * (255 - leopardOpacity)) + ((leopardColor >> 16) & 0xFF) * leopardOpacity) / 255;
        g = ((g * (255 - leopardOpacity)) + ((leopardColor >> 8) & 0xFF) * leopardOpacity) / 255;
        b = ((b * (255 - leopardOpacity)) + (leopardColor & 0xFF) * leopardOpacity) / 255;

        hoop.setPixelColor(x, Adafruit_NeoPixel::Color(r, g, b));
    }

    hoop.show();
    i++;
}

/**
 * @brief Stops the rainbow leopard effect.
 */
void RainbowLeopardEffect::stop() {
    // Implementation goes here
}
