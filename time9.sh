#!/bin/bash

# Define the folder containing the files to be executed
folder="/home/bbentle4/CS494/Sudoku-Analyzer/TestBoards/size9"

# Define the path to the executable
executable="/home/bbentle4/CS494/Sudoku-Analyzer/solver"

# Initialize variables to store accumulated time
total_time=0

# Check if the folder exists
if [ ! -d "$folder" ]; then
    echo "Folder not found!"
    exit 1
fi

# Check if the executable exists
if [ ! -x "$executable" ]; then
    echo "Executable not found or not executable!"
    exit 1
fi

count=1;
# Iterate over all files in the folder
for file in "$folder"/*; do
    # Record start time
    start=$(date +%s.%N)
    
    # Execute the file with the executable
    "$executable" "$file"
    
    # Record end time
    end=$(date +%s.%N)
    
    # Calculate execution time for the file
    execution_time=$(echo "$end - $start" | bc)
    
    # Accumulate execution time
    total_time=$(echo "$total_time + $execution_time" | bc)
    
    # Print accumulated execution time
    echo "$count: $execution_time seconds"
    ((count++))
done

# Print final accumulated execution time
echo "Total time taken: $total_time seconds"
