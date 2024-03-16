/*
    A basic backtracking algorithm. 
    From: https://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm315
    See the README.md for more details
*/
#include <iostream>
#include <vector> 
#include <string>

using namespace std;

class SudokuSolver {
    private:
        // Size of the board -- size x size
        int size;
        // Matrix version of board.
        vector<vector<int> > matrix;
        // Row, column, & square are 2D to keep track if a number is already
        // in the same row, column, square. (eg, row[2][1] = 0, means 1 has not 
        // been used in row 2, row[3][4] = 1 means 4 has been used in row 3) 
        vector<vector<int> > row, col, sq;
        // Keeps the count of the number of solutions.
        int ns; // ns = number (of) solutions
    
    public:
        // Initializes the vectors w/ the size
        void initialize (int inputSize)
        {
            size = inputSize;
            matrix.resize(size, vector<int>(size, 0));
            row.resize(size, vector<int>(size, 0));
            row.resize(size, vector<int>(size, 0));
            col.resize(size, vector<int>(size, 0));
            sq.resize(size, vector<int>(size, 0));
            ns = 0;

            for (int i = 0; i < size; i++) 
            {
                string row;
                cin >> row;
                vector<int> newRow;

                char lastDigit = static_cast<char>(size);
                for (char ch : row) 
                {
                    if (ch >= '1' && ch <= '9') {
                        newRow.push_back(ch - '0');
                    } else {
                        newRow.push_back(0);
                    }
                }
                matrix.push_back(newRow);
            }
        }
        // Preconditions: x, y must be within the bounds of the board.
        // Postconditions: Updates ns w/ the total count of the board's solutions.
        // Arguments: x, y are the row and column (respectively) being analyzed
        void countSolutions(int x, int y) 
        {
            // If we reached the end of the row
            if (x == sizeof(size))     ns++;
            else if (y == sizeof(size)) countSolutions(x + 1, 0); 
            else
            {
            }
        }
};

int main()
{
    SudokuSolver solver;
    int size;
    cin >> size;

    // Set board limits
    if (size < 4 || size > 100) return -1;

    // The board size has to be a perfect square. 
    if (isPerfectSquare(size))  solver.initialize(size);
    else    return -1;

    // Now we start solving the board. 
    solver.countSolutions(0, 0); 

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                 Helper fxs                                 */
/* -------------------------------------------------------------------------- */

// Returns true if argument is perfect square, else false
bool isPerfectSquare (int num)
{
    double squareRoot = sqrt(num);
    return squareRoot == floor(squareRoot);
}