# Sudoku-Analyzer

Inspired by the Silly Sudoku Top Coder problem. The aim is not to re-invent backtracking algorithms, but rather investigate how varying board sizes influence execution time and the number of solutions generated.

# BackTracking 
## solver.cpp

The algorithm for backtracking was the same one used in the TopCoder solution, [found here](https://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm315). I adjusted the code to work in C++ and work for multiple board sizes.

Compile using the following command:
`g++ -std=c++11 -stdlib=libc++ solver.cpp -o solver`

# Generator 
## generator.cpp
I wanted to produce hundreds to thousands of sudoku boards to test timing so I found a board generator algorithm on [Geeks4Geeks](https://www.geeksforgeeks.org/program-sudoku-generator/)

