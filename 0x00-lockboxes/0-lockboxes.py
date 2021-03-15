#!/usr/bin/python3
""" You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes. """


def canUnlockAll(boxes):
    """ method that determines if all the boxes can be opened,
        boxes is a list of lists """
    keys = [0]
    for k in keys:
        for key in boxes[k]:
            if key not in keys and key != 0 and key < len(boxes) and key != k:
                keys.append(key)
    if len(keys) == len(boxes):
        return True
    else:
        return False
