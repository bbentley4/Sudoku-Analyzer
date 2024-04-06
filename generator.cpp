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
#include <fstream>
#include <sstream>

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

        string numString;
        int num;

        // Load board (w/ ints)
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++)
            {
                cin >> numString;
                num = stoi(numString);
                board[i][j] = num;
            }
        }        

        // Load row, col, square values
        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < size; y++)
            {
                int val = board[x][y];
                int boxsize = sqrt(size);
                int square_index = (x/boxsize) * boxsize + (y/boxsize);

                if (val != 0) // Not a blank space
                {
                    if (row[x][val] == 1 || col[y][val] == 1 || sq[square_index][val] == 1)    
                    {
                        ns = -1; // Conflict! Invalid board
                    }
                    // Count that digit as occuring in that row, column, square
                    row[x][val] = 1;
                    col[y][val] = 1;
                    sq[square_index][val] = 1;
                }
            }
        }
    }

    void printBoardToFile(const std::string& filename) 
    {
        ofstream outFile(filename);

        if (!outFile.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        outFile << size << endl;
        for (int i = 0; i < size; ++i) 
        {
            for (int j = 0; j < size; ++j) 
            {
                outFile << board[i][j] << " ";
            }
            outFile << endl;
        }

        outFile.close();
    }
    
    // Preconditions: x, y must be within the bounds of the board.
    // Postconditions: Updates ns w/ the total count of the board's solutions.
    // Arguments: x, y are the row and column (respectively) being analyzed
    void countSolutions(int x, int y, string baseFileName) 
    {
        // Initializer determined an invalid board
        if (ns < 0)
        {
            ns = 0;
            return;
        }
        int val = board[x][y];
        //cout << "val: " << val << " x: " << x << " y: " << y << endl;
        // If we reached the end of the rows, we're done--we've found a solution.
        if (x == size)     
        {
            stringstream filenameStream;
            filenameStream << baseFileName << "_solution_" << ns << ".txt";
            string filename = filenameStream.str();
            printBoardToFile(filename);
            ns++;
        }
        // If we reached end of columns, go to the next row.
        else if (y == size) countSolutions(x + 1, 0, baseFileName); 
        else
        {
            int boxsize = sqrt(size);
            int square_index = (x/boxsize) * boxsize + (y/boxsize);
            //cout << "Square Index: " << square_index << endl;

            if (val == 0) // We can place any number here to test
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
                        if (y + 1 < size)
                        {
                            countSolutions(x, y + 1, baseFileName);
                        }
                        else if (x + 1 < size)
                        {
                            countSolutions(x + 1, 0, baseFileName);
                        }
                        else
                        {
                            ns++;
                            stringstream filenameStream;
                            filenameStream << baseFileName << "_solution_" << ns << ".txt";
                            string filename = filenameStream.str();
                            printBoardToFile(filename);
                        }
                        // Reset
                        row[x][i] = 0;
                        col[y][i] = 0;
                        sq[square_index][i] = 0;
                        board[x][y] = 0;
                    }
                }
            }
            else
            {
                if (y + 1 < size)
                {
                    countSolutions(x, y + 1, baseFileName);
                }
                else if (x + 1 < size)
                {
                    countSolutions(x + 1, 0, baseFileName);
                }
                else
                {
                    ns++;
                    stringstream filenameStream;
                    filenameStream << baseFileName << "_solution_" << ns << ".txt";
                    string filename = filenameStream.str();
                    printBoardToFile(filename);
                }
            }
        }
    }

    // Get the number of solutions.
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
        solver.countSolutions(0, 0, "4x4"); 
        cout << "Number of solutions: " << solver.get_ns() << endl;
    }
    else    return -1;

    return 0;
}