# OpenHoop Documentation

Welcome to the OpenHoop documentation! This document provides comprehensive guidance on creating LED images and effects for your hula hoop using the OpenHoop project.

## Table of Contents

1. [Introduction](#introduction)
2. [Creating LED Images](#creating-led-images)
3. [Developing LED Effects](#developing-led-effects)
4. [Advanced Features](#advanced-features)
5. [BLE Commands](#ble-commands)

## Introduction

OpenHoop is an open-source Arduino Nano 33 BLE Sense Rev2 project that seamlessly integrates cutting-edge technology with artistic expression. With OpenHoop, you can design and display custom LED effects and pixel art on your hula hoop. This documentation will guide you through the process of creating your own LED images and effects to personalize your hula hoop experience.

## Creating LED Images

### Overview

LED images are pixel art patterns that can be displayed on the LED strip of your hula hoop. Whether you're creating static designs or dynamic patterns, LED images offer endless possibilities for customization.

### LedImage Class Overview

The `LedImage` class is an abstract base class representing an image composed of LEDs. It provides methods for setting and getting pixel colors, as well as retrieving the width and height of the image.

### LedImage Class Methods

* **Constructor**: Initializes the LedImage object with a specified width and height.
* **Destructor**: Frees the memory allocated for the pixel array.
* **setPixel()**: Sets the color of a pixel at a specific position.
* **getPixel()**: Retrieves the color of a pixel at a specific position.
* **getWidth()**: Gets the width of the image.
* **getHeight()**: Gets the height of the image.

### Example: Creating a Custom LED Image

Follow these steps to create a custom LED image:

1. **Define the Image Dimensions**: Determine the width and height of your LED image based on the size of the desired pixel art image.

2. **Create the Header File (OpenHoop/include/images/YourCustomImage.h)**:

    ```c++
    #ifndef OPENHOOP_YOURCUSTOMIMAGE_H
    #define OPENHOOP_YOURCUSTOMIMAGE_H
    
    #include "LedImage.h"
    
    /**
     * @brief Represents an image of a custom pattern for the Hula Hoop LED display.
     */
    class YourCustomImage : public LedImage {
    public:
        /**
         * @brief Constructor for the YourCustomImage class.
         * @param primary_color Color for the main pattern.
         * @param secondary_color Color for the background or secondary pattern.
         */
        explicit YourCustomImage(uint32_t primary_color, uint32_t secondary_color);
    
    private:
        /**
         * @brief Set the colors for your custom pattern.
         * @param primary_color Color for the main pattern.
         * @param secondary_color Color for the background or secondary pattern.
         */
        void setPatternColors(uint32_t primary_color, uint32_t secondary_color) const;
    };
    
    #endif //OPENHOOP_YOURCUSTOMIMAGE_H
    
    ```

3. **Implement the Source File (OpenHoop/src/images/YourCustomImage.cpp)**:

    ```c++
    #include "../../include/images/YourCustomImage.h"
    
    YourCustomImage::YourCustomImage(uint32_t primary_color, uint32_t secondary_color) : LedImage(30, 30) {
        setPatternColors(primary_color, secondary_color);
    }
    
    void YourCustomImage::setPatternColors(uint32_t primary_color, uint32_t secondary_color) const {
        // Define the pixel colors for the pattern
        setPixel(0, 0, secondary_color);
        setPixel(1, 0, primary_color);
        setPixel(4, 0, primary_color);
        setPixel(2, 2, 0xffffff);
        setPixel(4, 2, 0xff0000);
        // Add more setPixel calls to complete the pattern
        ...
    }
    
    ```

4. **Upload to your hula hoop**: Incorporate the `YourCustomImage` class into your OpenHoop codebase and upload it to your Arduino Nano 33 BLE Sense Rev2 microcontroller connected to the Adafruit Neopixel strip of your hula hoop.

By following these steps, you can create and customize LED images for your hula hoop, adding visually appealing patterns and effects to enhance your performances.

## Developing LED Effects

### Overview

LED effects bring life to your hula hoop, allowing you to create dynamic visual experiences. Customizing patterns and developing LED effects involves defining the behavior, appearance, and interactivity of the LED display.

### Effect Class Overview

The `Effect` class is an abstract base class representing an LED effect. It provides pure virtual methods for starting, updating, and stopping an LED effect.

### Effect Class Methods

* **start()**: Initiates the effect.
* **update()**: Updates the effect.
* **stop()**: Terminates the effect.

### Developing a Custom LED Effect

#### Steps:

1. **Choose an Effect:**
    - Decide on the type of effect you want to create, such as a rainbow gradient, pulsating colors, or a scrolling pattern. Consider the visual impact and mood you want to convey with your effect.

2. **Identify Effect Elements:**
    - Determine which aspects of your LED effect can be customized. This may include color transitions, animation speeds, patterns, or any other visual or behavioral elements you wish to incorporate.

3. **Define Effect Logic and Parameters:**
    - Write code to define the behavior of your effect and the characteristics of the pattern. For example, you may define how colors transition, how patterns move or evolve, and any user-adjustable parameters such as speed or intensity.

4. **Implement Effect Variations:**
    - Create variables or parameters in your code to control the characteristics of the effect. This allows users to adjust the appearance dynamically to suit their preferences. Consider providing a range of customization options to enhance user experience.

5. **Test and Iterate:**
    - Upload the code to your hula hoop and test the effect. Make adjustments as needed to fine-tune the appearance and behavior, ensuring it meets your expectations and provides a visually appealing experience.

6. **Document Your Effect:**
    - Provide clear documentation for your effect, including instructions on usage and customization parameters. Explain how users can activate and interact with the effect, and provide guidance on adjusting parameters to achieve desired effects.

#### Example Effect Implementation:

Let's say we want to create a custom effect that simulates a flickering candle flame.

- **Effect Logic and Parameters:**
    - We'll define a pattern of color transitions to mimic the flickering flame, with variations in brightness and intensity.
    - Parameters such as speed, intensity, and color range will be adjustable to allow users to customize the appearance of the flame.

- **Implementation:**
    - We'll create a `CandleEffect` class that inherits from the `Effect` base class.
    - The `CandleEffect` class will implement the `start()`, `update()`, and `stop()` methods to initiate, update, and terminate the effect, respectively.
    - Within the `update()` method, we'll define the logic for the flickering flame effect, adjusting color transitions and brightness based on random fluctuations.

- **Integration with OpenHoop:**
    - Once the `CandleEffect` class is implemented, we'll add it to the `EffectType` enum in `OpenHoop/include/services/EffectService.h`.
    - In `OpenHoop/src/services/EffectService.cpp`, we'll update the `dispatchEffectCommand()` method to include a case for `EffectType::CANDLE`.
    - Users can then activate the custom candle flame effect by selecting it from the available options in the OpenHoop app.

By following these steps and implementing our custom candle flame effect, users can enjoy a unique and immersive visual experience during their hula hoop performances.

### Example: Implementing Custom Image in Custom Effect

To integrate a custom LED image into a custom LED effect, follow these steps:

1. **Define Custom Effect Header (`YourCustomEffect.h`)**:

    ```c++
    #ifndef OPENHOOP_YOURCUSTOMEFFECT_H
    #define OPENHOOP_YOURCUSTOMEFFECT_H

    #include "Effect.h"
    #include "../images/YourCustomImage.h" // Include the custom image header
    #include "Arduino.h"

    /**
     * @brief Represents a custom LED effect using a custom image pattern.
     */
    class YourCustomEffect : public Effect {
    public:
        YourCustomEffect();

        /**
         * @brief Start the custom effect.
         */
        void start() override;

        /**
         * @brief Update the custom effect.
         */
        void update() override;

        /**
         * @brief Stop the custom effect.
         */
        void stop() override;

    private:
        YourCustomImage customImage; // Instance of the custom image
        int counter;  ///< Counter for effect animation.
    };

    #endif //OPENHOOP_YOURCUSTOMEFFECT_H
    ```

2. **Implement Custom Effect Source (`YourCustomEffect.cpp`)**:

    ```c++
    #include "../../include/effects/YourCustomEffect.h"
    #include "../../include/utils/EffectUtils.h"

    YourCustomEffect::YourCustomEffect() : counter(0), customImage(0xFF0000, 0x0000FF) {
        // Constructor implementation goes here
    }

    void YourCustomEffect::start() {
        // Initialization code for the custom effect goes here
    }
   
    void YourCustomEffect::update() {
    // Effect update code goes here
    for (int x = 0; x < customImage.getWidth(); ++x) {
    for (int y = 0; y < customImage.getHeight(); ++y) {
    // Get the color of each pixel from the custom LED image
    uint32_t pixelColor = customImage.getPixel(x, y, 0x000000);
    
                // Apply the pixel color to the LED strip or perform other actions
                // based on the effect logic
            }
        }
    
        counter++;
    }

    void YourCustomEffect::stop() {
        // Cleanup code for the custom effect goes here
    }
    ```

By following these steps, you can seamlessly integrate a custom LED image into your custom LED effect, enhancing the visual experience of your hula hoop performances.

### Examples of Customized Patterns and LED Effects

1. **Rainbow Gradient**: Develop an effect that creates a smooth transition of colors across the LED strip, customizable by speed and direction.

2. **Pulsating Colors**: Create an effect that alternates between bright and dim LED intensities, with adjustable speed and intensity.

3. **Scrolling Pattern**: Develop an effect that displays a scrolling pattern or text message across the LED strip, customizable by content, speed, and direction.

4. **Interactive Modes**: Implement modes allowing users to control LED effects using external inputs, such as buttons or touch sensors.

## Advanced Features

### Overview

Advanced features in OpenHoop extend project capabilities and offer additional functionality for exploration and experimentation. These features may include sensor integration, interactive modes, network connectivity, and data visualization.

### Examples of Advanced Features

1. **Sensor integration**: Incorporate data from onboard sensors to influence LED effects in response to movement or environmental conditions.

2. **Interactive modes**: Implement modes allowing users to control LED effects using external inputs, such as buttons or touch sensors.

3. **Network connectivity**: Enable communication between multiple OpenHoop devices over a network, allowing synchronized LED displays.

4. **Data visualization**: Create LED effects visualizing real-time data streams, such as music visualization or weather forecasts.

## BLE Commands
Use the following commands to customize LED effects via Bluetooth Low Energy (BLE):

- `EffectType`: Change the LED effect to one of the predefined effects. Use the corresponding enum value for each effect.
- `SolidColor`: Set a solid color for the LED strip using RGB values. Specify the color without the '#' symbol.
- `EnergySavingMode`: Adjust energy-saving mode levels (0 to 3) to conserve power.

#### EffectType Enum

The `EffectType` enum defines various LED effects that can be applied to your hula hoop. Each effect is associated with a numeric value representing its index in the enum.

```c++
enum class EffectType {
    NO_EFFECT,          // No effect (default)
    RAINBOW,            // Rainbow effect
    ...
};
```

To change the LED effect, specify the corresponding `EffectType` value in your BLE command.

#### SolidColor Command

The `SolidColor` command allows you to set a solid color for the LED strip using RGB values. Provide the RGB color values without the '#' symbol. For example, to set the LED color to white, use 'FFFFFF'.

#### EnergySavingMode Command

The `EnergySavingMode` command enables you to adjust energy-saving mode levels to conserve power. There are four energy-saving mode levels, ranging from 0 to 3:

- Level 0 (Default): All LED effects operate at full intensity.
- Level 1: LED effects operate at 75% intensity.
- Level 2: LED effects operate at 50% intensity.
- Level 3: LED effects operate at 25% intensity.

To activate energy-saving mode, specify the desired level (0 to 3) in your BLE command. The LED effects will adjust their intensity accordingly.

### Utilizing EffectUtils

The `EffectUtils` class provides utility functions for enhancing LED effects, including energy-saving mode adjustments.

#### applyEnergySavingMode Function

The `applyEnergySavingMode()` function modifies the color of LEDs based on the specified energy-saving mode level. It takes a color value as input and returns the adjusted color according to the energy-saving mode level.

```c++
uint32_t EffectUtils::applyEnergySavingMode(uint32_t color);
```

You can integrate this function into your LED effect code to dynamically adjust LED intensity based on the selected energy-saving mode level.
