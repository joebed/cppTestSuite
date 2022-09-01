#!/bin/bash

# Assumes working directory is directory where main is located

g++ -o example example.cpp
echo 'Running without specifying a prefix'
echo './example'
./example
echo 'Running with prefix b'
echo './example b'
./example b
echo 'Running with prefix nah'
echo './example nah'
./example nah
rm example
