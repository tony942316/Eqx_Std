#!/bin/bash

rm -rf out/build/
mkdir out/build/
CXX=clang++-18 cmake -S . -B out/build/ -GNinja > /dev/null
