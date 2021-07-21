#!/usr/bin/python3

import sys


def nqueens_N(n, board, copy, row):
    if row == n:
        print(copy)
    else:
        for col in range(n):
            if all(col != c and row + col != r + c and
                    row - col != r - c for r, c in board):
                board.append([row, col])
                copy = board
                nqueens_N(n, board, copy, row + 1)
                board.remove([row, col])

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)
    else:
        if n < 4:
            print("N must be at least 4")
            exit(1)
    nqueens_N(n, [], [], 0)
