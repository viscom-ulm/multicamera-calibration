# Multi-camera calibration

This tool is based on the multicalib module of the OpenCV library. (https://docs.opencv.org/trunk/d2/d1c/tutorial_multi_camera_main.html)

## Getting Started

Calibrate a multi-camera system using pinhole model

### Prerequisites

Tested with:
Visual Studio 2015 and 2017
Install OpenCV (3.2) + contrib module

### Installing

Clone, Build, Compile.

```
git clone https://gitlab-mi.informatik.uni-ulm.de/ifr97/multicamera-calibration.git
cd multicamera-calibration
mkdir build && cd build
cmake .. -G "Visual Studio 15 2017 Win64"
```

Then open Visual Studio and build the solution.

## Authors

* **Sebastian Hartwig**