#!/bin/bash
# makes an empty board 
echo "16"

for ((row = 0; row < 16; row++)); do
    for ((col = 0; col < 16; col++)); do
        echo -n "0 "
    done
    echo # Add a newline after each row
done
