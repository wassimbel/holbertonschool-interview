#!/usr/bin/python3
""" method that determines if a given data set
    represents a valid UTF-8 encoding."""


def validUTF8(data):
    """ takes in data a list of int """
    ones = 0
    for i in data:
        bit_mask = 1 << 7
        if ones == 0:
            while i & bit_mask:
                ones += 1
                bit_mask >>= 1
            if ones > 4:
                return False
        elif i >> 6 != 2:
            return False
        if ones:
            ones -= 1
    return ones == 0
