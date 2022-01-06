#!/usr/bin/python3
""" Prime Game """


def is_prime(num):
    """ num: number to check
        Return: True if prime False if not"""
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            return False
    return True


def isWinner(x, nums):
    """x is the number of rounds and nums is an array of n """
    ben_pick = 0
    maria_pick = 0
    maria_round = 0
    ben_round = 0
    if x <= 0 and not nums:
        return None
    for i in nums:
        set_nums = set(k for k in range(1, i))
        for j in range(x):
            if j % 2 != 0 and is_prime(j):
                maria_pick += 1
            elif j % 2 == 0 and is_prime(j):
                ben_pick += 1
            else:
                continue
        if maria_pick > ben_pick:
            maria_round += 1
        else:
            ben_round += 1
    if maria_round > ben_round:
        return "Maria"
    elif ben_round > maria_round:
        return "Ben"
    return None
