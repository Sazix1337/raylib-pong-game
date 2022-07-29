# Raylib VSCode template for ARM OSX

## Prerequisite

To make sure the template works and you can use all the command listed below, use `xcode-select --install`, it can be a bit long though.

### VSCode extensions

- C/C++ 
- Makefile tools
- CodeLLDB 

### Homebrew dependencies

- cmake

> Use `brew install <name>`

## Installation

1. Download last raylib source version as ZIP file.
2. Then use cmake in 'raylib/src'
  - `cd path/to/raylib/src`
  - `make`
  - You should have a libraylib.a file that appeared (raylib builded file)
3. Extract libraylib.a, raylib.h and raymath.h from the 'raylib/src' folder and move them to lib folder in the template (replace old files).
4. Finally hit 'F5' to launch compiler & launch your program !

> /!\ Maybe the `macFrameworkPath` from 'c_cpp_properties.json' isn't valid, you should find the proper folder in '/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs'
