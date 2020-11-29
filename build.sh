#!/bin/bash
cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=Debug && cd build/debug && make && cd ../../

#cmake -S . -B build/release -DCMAKE_BUILD_TYPE=Release && cd build/release && make && cd ../../