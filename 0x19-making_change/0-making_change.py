#!/usr/bin/python3
"""  determine the fewest number
    of coins needed to meet a given amount total """


def makeChange(coins, total):
    """ method """
    x = 0
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    for i in coins:
        if total < i:
            continue
        q, r = divmod(total, i)
        x += q
        total = r
    if total != 0:
        return -1
    return x
