#! /usr/bin/bash
cmake --preset=default && cmake --build build
if [ $? -eq 0 ]; then
    ./build/learningcpp-gamedev
else
    echo "Build failed"
fi