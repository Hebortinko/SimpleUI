# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---
## [0.1.1] - 2026-04.4

### Added
- `Slider` - fully functional slider widget with setters max, min, increment, pos, color,

## [0.1.0] - 2026-03-12

### Added
- `Widget` — abstract base class for all UI elements (`handleEvent`, `update`, `draw`, `setPosition`, `setSize`, `setVisible`, `setEnabled`)
- `Button` — fully functional button widget with idle/hover/pressed/disabled states, smooth color-lerp animation, and centered label
- `Event<Args...>` — lightweight signal/callback system supporting multiple listeners
- `Theme` — global singleton for font, font size, colors and border settings shared across all widgets
- `WidgetStyle` / `ButtonStyle` — opt-in per-widget style overrides using `std::optional` fields
- `Presets` namespace — four ready-to-use button styles: `Primary`, `Danger`, `Success`, `Ghost`
- CMake integration — `SimpleUI` interface target for easy `FetchContent` or subdirectory inclusion

[0.1.0]: https://github.com/Hebortinko/SimpleUI/releases/tag/v0.1.0
