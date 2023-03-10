#!/bin/bash

LD_LIBRARY_PATH="$(pwd)/dependencies/SFML-master/dist/lib"
export LD_LIBRARY_PATH

./dist/game
