#!/bin/bash

# Set the compiler and flags
CXX=g++
CXXFLAGS="-Wall -O2"

# Output file name
OUTPUT="Homework01"

# Create a build directory if it doesn't exist
mkdir -p build

# Change to build directory
cd build

# Compile the source file
$CXX $CXXFLAGS ../Homework01.cpp -o $OUTPUT

# Optionally, run the executable after building
./$OUTPUT