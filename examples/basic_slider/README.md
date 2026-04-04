# Slider

Basic slider widget for `SimpleUI`.

Current implementation supports:

- `Slider<int>`
- `Slider<float>`
- minimum / maximum range
- step snapping
- mouse drag / click interaction
- `getValue()`
- color customization
- `onChange(...)` callback

## Constructor

```cpp
Slider<T> slider(min, max, step, position, size);
Slider<T> slider(min, max, step, position, size, initialValue);
```

Example:

```cpp
Slider<float> slider(0.f, 1.f, 0.05f, {80.f, 110.f}, {460.f, 40.f}, 0.10f);
```

This creates a slider:

- from `0.0` to `1.0`
- with step `0.05` (`1/20`)
- starting at `0.10`

## Minimal Usage

```cpp
#include "SimpleUI/Widgets/Slider.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({620, 260}), "Slider");
    window.setFramerateLimit(60);

    Slider<float> slider(0.f, 1.f, 0.05f, {80.f, 110.f}, {460.f, 40.f}, 0.10f);

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) window.close();
            slider.handleEvent(*event);
        }

        slider.update(0.f);

        window.clear(sf::Color::White);
        slider.draw(window);
        window.display();
    }
}
```

## Reading The Value

```cpp
float value = slider.getValue();
```

Or update it manually:

```cpp
slider.setValue(0.35f);
```

## Chainable API

Slider follows the same fluent style as the rest of the library:

```cpp
slider.position({100.f, 140.f})
      .size({320.f, 36.f})
      .range(0.f, 1.f)
      .increment(0.05f)
      .value(0.50f);
```

## Colors

You can style the slider separately:

```cpp
slider.color(sf::Color(70, 130, 180))
      .trackColor(sf::Color(210, 214, 220))
      .knobColor(sf::Color(100, 160, 210));
```

Meaning:

- `color(...)` sets active fill + outline + knob base color
- `trackColor(...)` sets the background track
- `knobColor(...)` overrides only the knob color

## Value Change Callback

Use `onChange(...)` when you want to react to movement:

```cpp
slider.onChange([](float value) {
    std::cout << "Slider value: " << value << std::endl;
});
```

## Full Example

Full example source is here:

- [`examples/basic_slider/main.cpp`](main.cpp)

The example shows:

- slider range `0.0 -> 1.0`
- step `0.05`
- current value rendered directly in the window
- console output on every change

## API Overview

Available getters:

```cpp
slider.getValue();
slider.getMinimum();
slider.getMaximum();
slider.getStep();
```

Available setters:

```cpp
slider.setValue(0.25f);
slider.setRange(0.f, 1.f);
slider.setStep(0.05f);
slider.setColor(sf::Color::Blue);
slider.setTrackColor(sf::Color(220, 220, 220));
slider.setKnobColor(sf::Color::White);
```

Available chain methods:

```cpp
slider.position({x, y});
slider.size({w, h});
slider.range(min, max);
slider.increment(step);
slider.value(current);
slider.color(color);
slider.trackColor(color);
slider.knobColor(color);
slider.onChange(callback);
```

## Notes

- Slider currently supports only `int` and `float`.
- Value is always clamped to the selected range.
- Value is snapped to the nearest valid step.
- Slider itself does not render numeric labels automatically.
- If you want the number on screen, render `slider.getValue()` with your own `sf::Text`, like in the example.

## Build And Run

From project root:

```bash
cmake -S . -B build -DSIMPLEUI_BUILD_EXAMPLES=ON
cmake --build build --target basic_slider
./build/examples/basic_slider/basic_slider
```
