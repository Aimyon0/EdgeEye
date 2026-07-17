# EdgeEye

A Linux-based real-time vision monitoring system built with C++ and OpenCV.

## Overview

EdgeEye is a Linux vision framework designed for real-time camera processing and future AI vision applications.

The project is developed incrementally, starting from camera acquisition and gradually evolving into a complete edge AI vision system.

---

## Features

Current features include:

- USB camera capture
- Real-time camera preview
- FPS monitoring
- CMake build system
- Modular C++ project architecture
- Screenshot capture
### Planned Features

- Video recording
- Multithreaded camera pipeline
- Qt graphical interface
- Serial communication with STM32
- YOLO object detection
- Edge AI inference

---

## Project Structure

```text
EdgeEye
│
├── CMakeLists.txt
├── README.md
├── config.json
├── include/
│   ├── camera.hpp
│   └── fps.hpp
│   └── screenshot.hpp
│
├── src/
│   ├── main.cpp
│   ├── camera.cpp
│   └── fps.cpp
│   └── screenshot.cpp
│
└── build/
```

---

## Environment

- Ubuntu
- GCC
- CMake
- OpenCV

---

## Build

```bash
mkdir build
cd build
cmake ..
make
```

---

## Run

```bash
./EdgeEye
```

---

## Version History
### v0.4

- Added screenshot capture module
- Press `S` to capture and save the current camera frame
- Added modular screenshot management with independent class design
- Automatically creates screenshot directory when saving images
### v0.3

- Added FPS counter module
- Display real-time FPS on the camera preview
- Introduced modular performance monitoring
![v0.3](images/V0.3.png)
### v0.2

- Integrated OpenCV
- Added USB camera capture
- Implemented real-time camera preview
- Added modular camera class

### v0.1

- Initial project setup
- C++ project structure
- CMake build system
- Basic executable framework