#!/bin/bash

rm -rf out
mkdir out
cd out
cmake ..
make
touch test.bld
echo "exit 9;" >>test.bld
./blud test.bld
./out
echo $?
cd ..
./clean.sh
