#!/usr/bin/python3
""" a method that calculates the fewest number of operations needed
    to result in exactly n H characters in a given file. """


def minOperations(n):
    """ n: number of H to be printed """

    if not isinstance(n, int) or n < 2:
        return 0
    i = 0
    min_op = 2
    while min_op <= n:
        while n % min_op == 0:
            i += min_op
            n /= min_op
        min_op += 1
    return i
