# Qt 3D Explorer
![Build workflow](https://github.com/martijnkoopman/Qt-3D-Explorer/actions/workflows/build.yml/badge.svg)

## Getting started

### Ensure a C++ compiler is installed
On Windows:
* Download and install Visual Studio
* Open Visual Studio Installer
  * Work load
    * Desktop development with C++

### Install Qt
1. Download the Qt Online installer
2. Run the Qt Maintenance tool (installer) and install the following components:
* Qt
  * Qt 6.2.x
    * Desktop gcc 64-bit
    * Qt Shader Tools
    * Additional Libraries
      * Qt 3D
  * Developer and Designer Tools
    * Qt Creator
    * CMake
    * Conan
    * Ninja

### Open project
1. Start Qt Creator
2. Open CMakeLists.txt