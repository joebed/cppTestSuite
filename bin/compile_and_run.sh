#!/bin/bash
pushd ~/src/c_projects/test_env/

g++ main.cpp
./a.out
rm a.out


popd