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

### Usage
```
Usage: ./multicalibration -[m|c|v|e|w|h|tc] calibration_result.xml file_list.xml
m - min matches (default 100)
v - verbose (default false)
e - show feature extraction (default false)
tc - termination count (default 10)
c - number of cameras
w - physical width of pattern in user defined unit (usually mm)
h - physical height of pattern in user defined unit (usually mm)


$ ./multicalibration.exe -c=36 -w=109 -h=82 all_images.xml calibration.xml
camera_count=36
patternWidth=109
patternHeight=82
initialized for camera 0 rms = 1.25491
initialized camera matrix for camera 0 is
[1854.2043, 0, 1063.5328;
 0, 1856.4719, 801.8584;
 0, 0, 1]
xi for camera 0 is []
initialized for camera 1 rms = 1.34718
initialized camera matrix for camera 1 is
[1841.5892, 0, 1050.0885;
 0, 1842.4463, 774.03088;
 0, 0, 1]
xi for camera 1 is []
...
```


## Authors

* **Sebastian Hartwig**