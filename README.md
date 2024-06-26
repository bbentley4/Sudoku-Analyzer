# Sudoku-Analyzer

Inspired by the Silly Sudoku Top Coder problem. The aim is not to re-invent backtracking algorithms, but rather investigate how varying board sizes influence execution time and the number of solutions generated.

# BackTracking 
## solver.cpp

The algorithm for backtracking was the same one used in the TopCoder solution, [found here](https://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm315). I adjusted the code to work in C++ and work for multiple board sizes.

Compile using the following command:
`g++ -std=c++11 -stdlib=libc++ solver.cpp -o solver`

# Generator 
Jacob Malloy (GTA) gave me the idea to use my solver code to generate boards.
1) Feed the solver a blank board.
2) It'll output every valid solution it comes up with
Note: You'll want to change line 227 depending on the size of your board

# Unsolved
unsolved.py takes the solved boards and removes cells at random at the ratio set by the user. `unsolved.py <empty-ratio>` I needed valid boards for the solver to solve so I can monitor the time.
Note: You'll want to change line 10 depending on the size of your board!

# Acknowledgments
This project was made possible thanks to the help of GTA Jacob Malloy, who provided valuable insights and feedback throughout development
