#!/bin/bash

# Counter variable to keep track of iterations
count=0

# Loop through input files
for input_file in $(ls SolvedBoards/size16/16x16_solution_*.txt); do
    # Increment the counter
    ((count++))

    # Check if the counter is divisible by 3
    if ((count % 5 == 0)); then
        # Extract the index from the input file name
        index=$(echo "$input_file" | cut -d'_' -f3 | cut -d'.' -f1)
        # Define output file name
        output_file="TestBoards/size16/16x16_unsolved_$index.txt"
        # Run the Python program with input redirection and output redirection
        # the number to the right of unsolved.py is the portion of blank cells
        python unsolved.py 0.5 < "$input_file" > "$output_file"
    fi
done


# I did every 5th one to have variety. I only want 1000 boards but I didn't want them all to be from too similar sub-trees