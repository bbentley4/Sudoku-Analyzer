/*
    Produces unsolved sudoku boards
    Source: https://www.geeksforgeeks.org/program-sudoku-generator/
    Edited by: Brenna Bentley
    See the README.md for more details
*/
#include <iostream>
#include <vector> 
#include <string>

using namespace std;

/* -------------------------------------------------------------------------- */
/*                                 HELPER FX                                  */
/* -------------------------------------------------------------------------- */

// Returns true if argument is perfect square, else false
bool isPerfectSquare (int num)
{
    double squareRoot = sqrt(num);
    return squareRoot == floor(squareRoot);
}
class SudokuGenerator {
public:

	vector<vector<int> > board;
    // Number of columns/rows. It's a size x size board
	int size;
    // Size of the sub-squares, ie, the square root of the size
	int sq_size;
    // No. Of missing digits 
	int N;

	// Constructor
	SudokuGenerator(int size, int N)
	{
		this->size = size;
		this->N = N;
	
		// Compute square root of size
		sq_size = (int)(sqrt(size));
		board.resize(size, vector<int>(size, 0));
	}

	// Fill the board
	void fillValues()
	{
		// Fill the diagonal of sq_size x sq_size matrices
		fillDiagonal();
		// Fill remaining blocks
		fillRemaining(0, sq_size);
		// Remove Randomly N digits to make game
		removeNDigits();
	}

	// Fill the diagonal sq_size number of sub-squares
	void fillDiagonal()
	{
		for (int i = 0; i < size; i = i + sq_size)
		{
			fillBox(i, i);
		}
	}

    // A recursive function to fill remaining cells
	bool fillRemaining(int i, int j)
	{
        // BASE CASES
        // if (reached end of row)
		if (j >= size && i < size - 1) 
        {
            // Move to next row, reset column
			i = i + 1;
			j = 0;
		}
        // if (reached end of board) then done.
		if (i >= size && j >= size)     return true;

        // PREVENT OVERWRITE OF FILL DIAGONAL
        // if (i < size of the sub-squares) then we're still in first row of squares
		if (i < sq_size) 
        {
            // if (j < size of the sub-squares) then we're the first square
            // So we make j = sq_size to prevent overwriting cells
            // e.g., In a 9x9, if i = 0 && (j = 0 || j = 1 || j = 2) then we set j = 3. 
			if (j < sq_size)    j = sq_size;
		}
        // if (i >= sq_size && i < size - sq_size) then we're in the inner squares
		else if (i < size - sq_size) 
        {
            // 
			if (j == (int)(i / sq_size) * sq_size)   j = j + sq_size;
		}
		else 
        {
			if (j == size - sq_size) 
            {
				i = i + 1;
				j = 0;
				if (i >= size)  return true;
			}
		}
		for (int num = 1; num <= size; num++) 
        {
			if (CheckIfSafe(i, j, num)) 
            {
				board[i][j] = num;
				if (fillRemaining(i, j + 1))    return true;
				board[i][j] = 0;
			}
		}
		return false;
	}

	// Returns false if given 3 x 3 block contains num.
	bool unUsedInBox(int rowStart, int colStart, int num)
	{
		for (int i = 0; i < sq_size; i++) 
        {
			for (int j = 0; j < sq_size; j++) 
            {
				if (board[rowStart + i][colStart + j] == num)   return false;
			}
		}
		return true;
	}

	// Fill a 3 x 3 boardrix.
	void fillBox(int row, int col)
	{
		int num;
		for (int i = 0; i < sq_size; i++) {
			for (int j = 0; j < sq_size; j++) {
				do {
					num = randomGenerator(size);
				} while (!unUsedInBox(row, col, num));
				board[row + i][col + j] = num;
			}
		}
	}
	// Random generator
	int randomGenerator(int num)
	{
		return (int)floor(
			(float)(rand() / double(RAND_MAX) * num + 1));
	}
	// Check if safe to put in cell
	bool CheckIfSafe(int i, int j, int num)
	{
		return (
			unUsedInRow(i, num) && unUsedInCol(j, num)
			&& unUsedInBox(i - i % sq_size, j - j % sq_size, num));
	}
	// check in the row for existence
	bool unUsedInRow(int i, int num)
	{
		for (int j = 0; j < size; j++) {
			if (board[i][j] == num) {
				return false;
			}
		}
		return true;
	}
	// check in the row for existence
	bool unUsedInCol(int j, int num)
	{
		for (int i = 0; i < size; i++) {
			if (board[i][j] == num) {
				return false;
			}
		}
		return true;
	}
	
	// Remove the N no. of digits to
	// complete game
	void removeNDigits()
	{
		int count = N;
		while (count != 0) {
			int cellId = randomGenerator(size * size) - 1;
			// System.out.println(cellId);
			// extract coordinates i and j
			int i = (cellId / size);
			int j = cellId % size;
			if (j != 0) {
				j = j - 1;
			}
			// System.out.println(i+" "+j);
			if (board[i][j] != 0) {
				count--;
				board[i][j] = 0;
			}
		}
	}
	// Print sudoku
	void printSudoku()
	{
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << to_string(board[i][j]) + " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

// Driver code
int main()
{
	int size = 9;
	int N = 20;
	SudokuGenerator* sudoku = new SudokuGenerator(size, N);
	sudoku->fillValues();
	sudoku->printSudoku();
	return 0;
}

// This code is contributed by Aarti_Rathi
