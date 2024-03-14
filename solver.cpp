/*
    A basic backtracking algorithm. 
    From: https://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm315
    See the README.md for more details
*/

#include <vector> 
#include <string>

using namespace std;

class Sudoku {
    private:
        // Board is input as a string
        string board;
        // Board needs to be a matrix to be analyzed
        vector<vector<int> > board;
        // Row, Column, & Square are 2D to keep track if a number is already in the same row, column, square
        vector<vector<int> > row, col, sq;
        int num_sol; //number of solutions
    
    public:
        // Preconditions: x, y must be within the bounds of the board.
        // Arguments: x, y are coordinates of starting cell. 
        void countSolutions(int x, int y) 
        {
            if (x == 4)
        }
}