# EdgeEye

A Linux-based real-time vision monitoring system built with C++ and OpenCV.

## Overview

EdgeEye is a Linux vision framework designed for real-time camera processing and future AI vision applications.

The project is developed step by step, starting from basic camera acquisition and gradually extending to multithreading, GUI interaction, and edge AI deployment.

## Features

### v0.2

- C++ project structure
- CMake build system
- OpenCV integration
- USB camera capture
- Real-time camera preview

### Planned Features

- FPS monitoring
- Screenshot capture
- Video recording
- Multithreaded camera pipeline
- Qt graphical interface
- Serial communication with STM32
- YOLO object detection

## Project Structure

```
EdgeEye
│
├── CMakeLists.txt
├── README.md
│
├── include/
│   └── camera.hpp
│
├── src/
│   ├── main.cpp
│   └── camera.cpp
│
└── build/
```

## Environment

- Ubuntu
- GCC
- CMake
- OpenCV

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Run

```bash
./EdgeEye
```

## Version History

### v0.1

- Initial project setup.
- C++ project structure
- CMake build system
- Basic executable framework

### v0.2

- OpenCV camera support.
- Added camera module
- Added USB camera capture
- Added real-time preview
