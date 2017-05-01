# waifu2x (converter only version)

This is a reimplementation of waifu2x ([original](https://github.com/nagadomi/waifu2x)) converter function, in C++, using OpenCV.
This is also a reimplementation of [waifu2x python version](https://marcan.st/transf/waifu2x.py) by [Hector Martin](https://marcan.st/blog/).
You can use this as command-line tool of image noise reduction or/and scaling.


## Dependencies

### Platform

 * Ubuntu
 * Windows10

### Libraries

 * [OpenCV](http://opencv.org/)(C++, version 3.0.0 rc1)
 * [picojson](https://github.com/kazuho/picojson)
 * [TCLAP(Templatized C++ Command Line Parser Library)](http://tclap.sourceforge.net/)

## How to build

### for Ubuntu
install OpenCV from sources.
```
# depends
sudo apt-get install build-essential cmake git
sudo apt-get install ffmpeg libopencv-dev libgtk-3-dev python-numpy python3-numpy libdc1394-22 libdc1394-22-dev libjpeg-dev libpng12-dev libtiff5-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libxine2-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libv4l-dev libtbb-dev qtbase5-dev libfaac-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev x264 v4l-utils unzip

# download
wget https://github.com/Itseez/opencv/archive/3.1.0.zip
unzip 3.1.0

# build 
cd opencv-3.1.0
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D WITH_V4L=ON -D WITH_QT=ON -D WITH_OPENGL=ON ..
make
sudo make install
sudo /bin/bash -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig

# update pkgconfig
# update opencv pkgconfig '/usr/local/lib/pkgconfig/opencv.pc'
# delete '-lippicv' 

```
and then,

```
cd build
make
```

### for windows10
1. open build/waifu2x.sln with visual studio 2015
2. build solution.


## Usage

Usage of this program can be seen by executing this with `--help` option.

