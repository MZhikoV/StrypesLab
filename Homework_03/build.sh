#!/bin/bash

# Set variables for the C++ source file and output binary
SOURCE_FILE="Homework_03.cpp"
OUTPUT_BINARY="homework_03"

# Compile the C++ source file using g++ compiler
g++ -std=c++11 -Wall -o $OUTPUT_BINARY $SOURCE_FILE
