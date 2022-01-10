#!/usr/bin/python3
""" returns a list of lists of integers
    representing the Pascal’s triangle of n """


def pascal_triangle(n):
    """ n: int """
    x = []
    if n <= 0:
        return x
    for i in range(n):
        a = [1]
        if x:
            for j in range(i):
                a.append(sum(x[-1][j:j+2]))
        x.append(a)
    return x
