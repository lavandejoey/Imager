# Imager —— A Qt 5 based image viewer

[//]: # (Badges for build, license MIT, Qt5, opencv)
[![Stars](https://img.shields.io/github/stars/lavandejoey/Imager.svg)]()
[![License](https://img.shields.io/badge/License-MIT-green?logo=mit)](https://opensource.org/licenses/MIT)
[![CMake](https://img.shields.io/badge/CMake-3.20.5-blue.svg)]()
[![Qt](https://img.shields.io/badge/Qt-5.15.14-blue.svg)]()
[![OpenCV](https://img.shields.io/badge/OpenCV-4.8.0-blue.svg)]()


[//]: # (Introduction)
[Imager](https://github.com/lavandejoey/Imager) is a C++ implemented application basing on the Qt 5.

## Features

- Start and stop the camera.
- Capture and save the image.
- Focus and rotate the image.
- Configure the camera parameters.

## Build and Installation

### Linux (Tested on Ubuntu 22.04)

1. Clone the repository:
   ```
    git clone https://github.com/lavandejoey/Imager.git
   ```
2. Navigate to the project directory:
   ```
    cd Imager
   ```
3. Create a build directory and navigate into it:
   ```
    mkdir build && cd build
   ```
4. Run CMake to configure the project and generate a Makefile, then build the project:
   ```
    cmake .. && make
   ```
5. Run the application:
   ```
    ./Imager
   ```

### Windows (Tested on Windows 11)

1. Clone the repository:
   ```
    git clone https://github.com/lavandejoey/Imager.git
   ```
2. Open the project in CLion 2023.3.2.
3. Build the project by clicking on the build button.
4. Run the application by clicking on the run button.

## TODO list

- [x] Creating REPO and README.
- [x] Environment setup & Simple Qt app.
- [x] Basic Functions: capture, save and load.
- [x] Beautify the UI.
- [x] Check and warning for the invalid camera.
- [x] Advanced Functions for photography: Rotation, Focus, etc.
- [ ] Advanced Functions for image processing: Filters, etc., supported by OpenCV.

## Contributors and Contact

- LIU Ziyi (<a href="https://JoshuaZiyiLIU.com">Joshua</a>) - <a href="mailto:lavandejoey@outlook.com?subject=[GitHub-Imager] Contact">
  lavandejoey@outlook.com</a>