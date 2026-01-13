# Assetto Corsa Modkit

I built this app for it to act as a helper program, automating any of my modding workflows for Assetto Corsa that can be. The killer for my productivity happened to be all of those tedious tasks which kept me from moving to the next step in my workflow before I could ultimately test my changes in-game. Anything that can be automated along the way, this app should be there to accomodate.

## Status

The development of this project is halted if the README still contains this message. This is due to the outcomes of the project largely being met with Fluffy's Track Exporter that launched not long from the first few development releases of this project. I have used the Track Exporter tool which is a blender add-on for my track modding needs and have found that much of what I hoped to automate through AC-Modkit currently is already in some way shape or form included in this add-on; As such, there isn't a need for AC-Modkit to be built out further. It will reamin a template for a C++ written Qt app that I can refer back to for further Qt app development in my other repositories.

## Features

- Converting and saving .PNG files as .DDS texture images.
- Previewing the texture image before conversion.

## Requirements

- Qt 6 with the Widgets module (required across the app and supporting libraries)
- DirectXTex (Windows builds only; texture processing support)

## Installation

1. Clone the repository and create a build directory:
   ```bash
   git clone https://github.com/qasimkamran/AC-ModKit.git
   cd AC-ModKit
   cmake -S . -B build
   ```
2. Build the binaries with CMake (default target builds the GUI and libraries):
   ```bash
   cmake --build build
   ```
3. Optionally install the executable and assets (installs to your chosen prefix):
   ```bash
   cmake --install build --prefix <install-dir>
   ```

## Build Configuration

- The project targets C++17 and relies on the Qt6 Widgets module discovered via `find_package(Qt6 COMPONENTS Widgets REQUIRED)`. If Qt lives outside standard locations, set `CMAKE_PREFIX_PATH=/path/to/qt/6.x/gcc_64` (or equivalent) before configuring.
- Windows builds automatically fetch DirectXTex through CMake's `FetchContent`. Non-Windows platforms include stub headers from the `stubs/` directory, so no extra action is required.
- A post-build step copies the `assets/` directory next to the produced `ac_modkit` binary; keep that folder available if you relocate the executable manually.
- Tests live in `tests/` and can be built via `cmake --build build --target texture_correct_tests` (and run directly from `build/tests` once compiled).

## Screenshots

The GUI design and all the used widgets have been laid out using Qt Designer, the output `ui.h` file must then be included in-place of the committed one to this repository to replace existing widgets and styling throughout the GUI. Bear in mind that many of the names may need refactoring across the repository if they have been altered for existing widgets.

## License

This project is distributed under the terms of the [MIT License](LICENSE).
