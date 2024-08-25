#!/bin/bash


output=$(make 2>&1 > /dev/null)
if [ $? -eq 0 ]; then
    ./cub ./map/test.cub
else
    echo "$output"
fi
