#!/bin/bash

if [ ! -d build ]; then
	mkdir build
fi

cd build

# Generate the build files using CMake
cmake ..

# Build the project
make

# Run the executable
./blud
