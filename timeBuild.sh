#!/bin/bash

echo "Start"

./clean.sh
echo ""
echo "Cold MultiThreaded..."
echo "Header..."
time cmake --build out/build -j4 --target HeaderMain -- --quiet
echo ""
echo "Module..."
time cmake --build out/build -j4 --target ModMain -- --quiet

./clean.sh
echo ""
echo "Cold SingleThreaded..."
echo "Header..."
time cmake --build out/build -j1 --target HeaderMain -- --quiet
echo ""
echo "Module..."
time cmake --build out/build -j1 --target ModMain -- --quiet

echo ""
echo "Hot MultiThreaded"
touch HeaderMain.cpp
touch ModMain.cpp
echo "Header..."
time cmake --build out/build -j4 --target HeaderMain -- --quiet
echo ""
echo "Module..."
time cmake --build out/build -j4 --target ModMain -- --quiet

echo ""
echo "Hot SingleThreaded..."
touch HeaderMain.cpp
touch ModMain.cpp
echo "Header..."
time cmake --build out/build -j1 --target HeaderMain -- --quiet
echo ""
echo "Module..."
time cmake --build out/build -j1 --target ModMain -- --quiet
