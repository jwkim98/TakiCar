#!/usr/bin/env bash

set -e

export TRAVIS_COMPILER=g++-8
export CXX=g++-8
export CXX_FOR_BUILD=g++-8
export CC=gcc-8
export CC_FOR_BUILD=gcc-8

export NUM_JOBS=1

mkdir build
cd build
cmake ..
make
bin/UnitTests