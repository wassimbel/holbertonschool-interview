#!/usr/bin/python3
""" Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water
    will be retained after it rains.  """


def rain(walls):
    """ walls: a list of non-negative integers"""
    if not walls:
        return 0

    l, r = 0, len(walls) - 1
    lmax, rmax = walls[l], walls[r]
    level = 0

    while l < r:
        if lmax < rmax:
            l += 1
            lmax = max(lmax, walls[l])
            level += lmax - walls[l]
        else:
            r -= 1
            rmax = max(rmax, walls[r])
            level += rmax - walls[r]
    return (level)
