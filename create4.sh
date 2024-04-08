#!/bin/bash

# Loop through input files
for input_file in $(ls SolvedBoards/size4/4x4_solution_*.txt); do
    # Extract the index from the input file name
    index=$(echo "$input_file" | cut -d'_' -f3 | cut -d'.' -f1)
    # Define output file name
    output_file="TestBoards/size4/4x4_unsolved_$((index+864)).txt"
    # Run the Python program with input redirection and output redirection
    # the number to the right of unsolved.py is the portion of blank cells
    python unsolved.py 0.6 < "$input_file" > "$output_file"
done

# For 4x4 since there are only 288 solutions for a blank board, I run this a few more times with a different
# portion of blank cells and with a new i value so I can have 1000 boards