#!/usr/bin/python3
""" Given an n x n 2D matrix, rotate it 90 degrees clockwise. """


def rotate_2d_matrix(matrix):
    """ returns nothing """
    copy = list(zip(*matrix[::-1]))
    i = len(matrix)
    j = len(matrix[0])
    for k in range(i):
        for l in range(j):
            matrix[k][l] = copy[k][l]
