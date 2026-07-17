# EdgeEye Development Roadmap

> **Project Goal**
>
> Build EdgeEye into a complete Linux-based edge vision framework, covering camera acquisition, multithreading, GUI, communication, and AI inference. The project focuses on software engineering practices rather than only implementing algorithms.

---

# Overall Architecture

```
                +-----------------------+
                |      USB Camera       |
                +-----------+-----------+
                            |
                            v
                    Camera Capture
                            |
                            v
                 Image Processing Pipeline
                            |
          +-----------------+-----------------+
          |                                   |
          v                                   v
     Display / GUI                     AI Inference
          |                                   |
          +-----------------+-----------------+
                            |
                            v
                    External Communication
                            |
                            v
                     Edge AI Deployment
```

---

# Development Roadmap

```
v0.1
Project Initialization
        │
        ▼
v0.2
Camera Capture
        │
        ▼
v0.3
FPS Monitor
        │
        ▼
v0.4
Screenshot Capture
        │
        ▼
v0.5
Video Recording
        │
        ▼
v0.6
Multithread Pipeline
        │
        ▼
v0.7
Qt GUI
        │
        ▼
v0.8
Serial Communication
        │
        ▼
v0.9
Configuration System
        │
        ▼
v1.0
ONNX Runtime Integration
        │
        ▼
v1.1
YOLO Object Detection
        │
        ▼
v1.2
Object Tracking
        │
        ▼
v1.3
Performance Optimization
        │
        ▼
v2.0
Deploy on RK3588 / Horizon Platform
```

---

# v0.1 — Initial Project

## Goal

Build the project framework.

## Features

* CMake project
* Git repository
* README
* Basic executable

## Learn

* CMake
* GCC
* Git workflow

---

# v0.2 — Camera Module

## Goal

Acquire camera frames.

## Features

* OpenCV
* USB Camera
* Camera class
* Real-time preview

## Learn

* VideoCapture
* Project modularization

---

# v0.3 — FPS Monitor

## Goal

Measure real-time performance.

## Features

* FPSCounter class
* Real-time FPS overlay

## Learn

* chrono
* Performance monitoring

---

# v0.4 — Screenshot Capture

## Goal

Capture still images.

## Features

* Screenshot class
* PNG saving
* Timestamp filenames
* Screenshots directory
* Press **S** to capture

## Learn

* cv::imwrite()
* Filesystem
* Time API

---

# v0.5 — Video Recording

## Goal

Record videos.

## Features

* VideoWriter
* Start/Stop recording
* MP4 output
* Recording indicator
* Automatic filename

## Keyboard

```
R
```

Start / Stop Recording

## Learn

* Video encoding
* File IO
* Continuous frame writing

---

# v0.6 — Multithread Pipeline

## Goal

Separate capture, display and processing.

## Architecture

```
Camera Thread
      │
      ▼
 Frame Queue
      │
      ▼
Display Thread

Processing Thread
```

## Features

* std::thread
* Mutex
* Condition Variable
* Thread-safe queue

## Learn

* Producer Consumer
* Synchronization

---

# v0.7 — Qt GUI

## Goal

Professional desktop interface.

## Interface

```
+--------------------------------------+
|              EdgeEye                 |
+--------------------------------------+
|                                      |
|              Camera                  |
|                                      |
| FPS:30  Recording:OFF                |
|                                      |
+--------------------------------------+
| Start Stop Screenshot Record Setting |
+--------------------------------------+
```

## Learn

* Qt Widgets
* Signals & Slots

---

# v0.8 — Serial Communication

## Goal

Connect STM32.

## Features

* UART
* Serial Monitor
* Send commands
* Receive status

Example

```
PC
 ↓
UART
 ↓
STM32
```

Applications

* Robot
* Embedded Controller
* AI Edge Device

---

# v0.9 — Configuration System

## Goal

Store settings.

## Features

* JSON configuration
* Camera resolution
* FPS
* Save directory

Learn

* nlohmann/json

---

# v1.0 — ONNX Runtime

## Goal

Run AI models.

## Pipeline

```
Camera
 ↓
Resize
 ↓
Normalize
 ↓
ONNX Runtime
 ↓
Classification
```

Learn

* ONNX
* Tensor processing

---

# v1.1 — YOLO Detection

## Goal

Real-time object detection.

## Features

* YOLOv8
* Bounding Box
* Confidence
* FPS

Learn

* DNN
* NMS
* Inference pipeline

---

# v1.2 — Object Tracking

## Goal

Track objects.

Possible algorithms

* ByteTrack
* DeepSORT

---

# v1.3 — Performance Optimization

## Features

* Double Buffer
* Queue Optimization
* CPU profiling
* Memory optimization

Learn

* High-performance C++

---

# v2.0 — Embedded AI Deployment

Target Platforms

* RK3568
* RK3588
* Horizon RDK
* Jetson

Replace

```
OpenCV DNN
↓

NPU Runtime
```

Possible Frameworks

* RKNN
* Horizon BPU
* TensorRT

---

# Engineering Practices

Every version should follow the same workflow.

```
Develop
    ↓
Build
    ↓
Run
    ↓
Test
    ↓
Commit
    ↓
Push
    ↓
Release
    ↓
Update README
```

---

# Git Commit Style

Examples

```
Initial project

Add camera module

Add FPS monitor

Add screenshot capture

Add video recording

Implement multithread pipeline

Add Qt GUI

Add serial communication

Integrate ONNX Runtime

Implement YOLO detection
```

---

# GitHub Release Style

Example

```
EdgeEye v0.4 - Screenshot Capture
```

Template

```
## Added

...

## Improved

...

## Next

...
```

---

# README Evolution

Always keep README updated.

Include

* Overview
* Features
* Architecture
* Build
* Usage
* Version History
* Screenshots

---

# Repository Structure (Target)

```
EdgeEye
│
├── include/
├── src/
├── assets/
├── docs/
├── images/
├── screenshots/
├── videos/
├── models/
├── config/
├── tests/
├── CMakeLists.txt
├── README.md
└── LICENSE
```

---

# Long-Term Goal

By the time EdgeEye reaches **v2.0**, it should demonstrate:

* Modern C++ programming
* Linux development
* CMake
* Git workflow
* OpenCV
* Multithreading
* Qt GUI
* Serial communication
* ONNX Runtime
* YOLO deployment
* Engineering-oriented project organization
* Readable documentation and release history

This progression mirrors the skills commonly expected for Linux embedded, edge AI, robotics, and computer vision software engineering roles.
