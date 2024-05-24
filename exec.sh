#! /usr/bin/bash
clear
cmake --preset=default

if [ $? -ne 0 ]; then
    echo "CMake failed"
    exit 1
fi

cmake --build build

if [ $? -eq 0 ]; then
    ./build/learningcpp-gamedev
else
    echo "Build failed"
fi

# clang-format -i ./src/*