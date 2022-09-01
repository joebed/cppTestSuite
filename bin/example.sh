#!/bin/bash

# Assumes working directory is directory where main is located

g++ -o example.out example.cpp
echo 'running without specifying a prefix'
echo './example.out'
./example.out
echo 'running with prefix b'
echo './example.out b'
./example.out b
echo 'running with prefix nah'
echo './example.out nah'
./example.out nah
echo 'cleaning up'
rm example.out
