#!/bin/bash

# Define the input file containing the board
input_file="empty.txt"

# Define the command to run the solver
solver_command="./solver"

# Run the solver 5 times and record the times
for ((i=1; i<=1; i++)); do
    # Record the start time
    start=$(date +%s.%N)
    
    # Run the solver with input redirection from the board file and capture the output
    output= $solver_command $input_file
    
    # Record the end time
    end=$(date +%s.%N)
    
    # Calculate the elapsed time
    elapsed=$(echo "$end - $start" | bc)
    
    # Print the result
    echo "$i: $elapsed seconds"
done
