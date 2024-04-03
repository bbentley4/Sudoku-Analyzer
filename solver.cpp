/*
    A basic backtracking algorithm. 
    Source: https://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm315
    Edited by: Brenna Bentley
    See the README.md for more details
*/
#include <iostream>
#include <vector> 
#include <string>
#include <cmath>

using namespace std;

/* -------------------------------------------------------------------------- */
/*                             SUDOKU SOLVER CLASS                            */
/* -------------------------------------------------------------------------- */
class SudokuSolver {
private:
    // Size of the board -- size x size
    int size;
    // int version of input board.
    vector<vector<int> > board;
    // Row, column, & square are 2D to keep track if a number is already
    // in the same row, column, square. (eg, row[2][1] = 0, means 1 has not 
    // been used in row 2, row[3][4] = 1 means 4 has been used in row 3) 
    vector<vector<int> > row, col, sq;
    // Keeps the count of the number of solutions.
    int ns; // ns = number (of) solutions

public:
    // Constructor
    SudokuSolver(int inputSize)
    {
        size = inputSize;
        board.resize(size, vector<int>(size, 0));
        row.resize(size, vector<int>(size, 0));
        col.resize(size, vector<int>(size, 0));
        sq.resize(size, vector<int>(size, 0));
        ns = 0;

        for (int i = 0; i < size; i++) 
        {
            string row;
            cin >> row;
            vector<int> newRow;

            // Converts int to ASCII char
            char lastDigit = static_cast<char>(size);
            for (int i = 0; i < row.length(); i++)
            {
                char ch = row[i];   // Converts ASCII char to int
                if (ch >= '1' && ch <= lastDigit)     newRow.push_back(ch - '0'); 
                else    newRow.push_back(0); // Push a 0 where there is a blank space
            }
            board.push_back(newRow);
        }
    }
    
    // Preconditions: x, y must be within the bounds of the board.
    // Postconditions: Updates ns w/ the total count of the board's solutions.
    // Arguments: x, y are the row and column (respectively) being analyzed
    void countSolutions(int x, int y) 
    {
        int val = board[x][y];
        // If we reached the end of the rows, we're done--we've found a solution.
        if (x == size)     ns++;
        // If we reached end of columns, go to the next row.
        else if (y == size) countSolutions(x + 1, 0); 
        else
        {
            int sqrtsize = sqrt(size);
            int square_index = (x/sqrtsize) * sqrtsize + (y/sqrtsize);

            if (val != 0) // Not a blank space
            {
                if (row[x][val] == 0 && col[y][val] == 0 && sq[square_index][val] == 0)
                {
                    // Count that digit as occuring in that row, column, square
                    row[x][val] = 1;
                    col[y][val] = 1;
                    sq[square_index][val] = 1;
                    // Call recursively to check the rest of this line, column, and square
                    countSolutions(x, y + 1);
                    // Reset
                    row[x][val] = 0;
                    col[y][val] = 0;
                    sq[square_index][val] = 0;
                }
            }
            else // It is a blank space
            {
                for (int i = 0; i < size; i++)
                {
                    if (row[x][i] == 0 && col[y][i] == 0 && sq[square_index][i] == 0)
                    {
                        // Set the cell to the i (since val is a blank space).
                        board[x][y] = i;
                        // Count that digit as occuring in that row, column, square
                        row[x][i] = 1;
                        col[y][i] = 1;
                        sq[square_index][i] = 1;
                        // Call recursively to check the rest of this line, column, and square
                        countSolutions(x, y + 1);
                        // Reset
                        row[x][i] = 0;
                        col[y][i] = 0;
                        sq[square_index][i] = 0;
                    }
                }
            }
        }
    }

    int get_ns()
        {
            return ns;
        }
};

/* -------------------------------------------------------------------------- */
/*                                 HELPER FXS                                 */
/* -------------------------------------------------------------------------- */

// Returns true if argument is perfect square, else false
bool isPerfectSquare (int num)
{
    double squareRoot = sqrt(num);
    return squareRoot == floor(squareRoot);
}

/* -------------------------------------------------------------------------- */
/*                                    MAIN                                    */
/* -------------------------------------------------------------------------- */
int main()
{
    int size;
    cin >> size;

    // Set board limits
    if (size < 4 || size > 100) return -1;

    // The board size has to be a perfect square or don't bother. 
    if (isPerfectSquare(size))
    {
        SudokuSolver solver(size);
        // Now we start solving the board. 
        solver.countSolutions(0, 0); 
        cout << "Number of solutions: " << solver.get_ns() << endl;
    }
    else    return -1;

    return 0;
}