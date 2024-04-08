#!/bin/bash

# Loop through input files
for input_file in $(ls SolvedBoards/size9/9x9_solution_*.txt); do
    # Extract the index from the input file name
    index=$(echo "$input_file" | cut -d'_' -f3 | cut -d'.' -f1)
    # Define output file name
    output_file="TestBoards/size9/9x9_unsolved_$index.txt"
    # Run the Python program with input redirection and output redirection
    # the number to the right of unsolved.py is the portion of blank cells
    python unsolved.py 0.5 < "$input_file" > "$output_file"
done
