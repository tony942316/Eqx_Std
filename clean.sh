#!/bin/bash

rm -rf out/build/
mkdir out/build/
CXX=clang++-17 cmake -S . -B out/build/ -GNinja > /dev/null
