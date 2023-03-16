#!/bin/bash

LD_LIBRARY_PATH="$LD_LIBRARY_PATH":"$(pwd)/dependencies/SFML-master/dist/lib":"$(pwd)/dependencies/fruit-3.7.1/dist/lib"
export LD_LIBRARY_PATH

./dist/notebox
