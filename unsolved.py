import sys
import random

def read_sudoku_board():
    lines = sys.stdin.readlines()
    sudoku_board = [[int(num) for num in line.split()] for line in lines]
    return sudoku_board

def write_sudoku_board(sudoku_board):
    print('4') #Change to the size of the board 
    for row in sudoku_board:
        print(' '.join(map(str, row)))

def empty_cells(sudoku_board, empty_ratio):
    total_cells = len(sudoku_board) * len(sudoku_board[0])
    num_empty_cells = int(total_cells * empty_ratio)
    cells = [(i, j) for i in range(len(sudoku_board)) for j in range(len(sudoku_board[0]))]
    random.shuffle(cells)
    for k in range(num_empty_cells):
        i, j = cells[k]
        sudoku_board[i][j] = 0

def main():
    sudoku_board = read_sudoku_board()
    if len(sys.argv) != 2:
        print("Usage: python unsolved.py <empty_ratio>")
        sys.exit(1)
    empty_ratio = float(sys.argv[1])
    empty_cells(sudoku_board, empty_ratio)
    write_sudoku_board(sudoku_board)

if __name__ == "__main__":
    main()
