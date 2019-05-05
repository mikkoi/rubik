#!/usr/bin/env bash
set -x
git clone https://github.com/libcheck/check.git
cd check
git remote add mikkoi git@github.com:mikkoi/check.git
git fetch mikkoi
git checkout improve-import
cd ..
mkdir -p build-Release-check
rm -Rf build-Release-check/*
mkdir -p install-Release-check
rm -Rf install-Release-check/*
cd build-Release-check
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../install-Release-check ../check
make install

