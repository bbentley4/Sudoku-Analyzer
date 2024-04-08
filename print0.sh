#!/bin/bash

for ((row = 0; row < 25; row++)); do
    for ((col = 0; col < 25; col++)); do
        echo -n "0 "
    done
    echo # Add a newline after each row
done
