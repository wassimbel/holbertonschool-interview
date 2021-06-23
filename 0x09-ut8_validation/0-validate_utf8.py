#!/usr/bin/python3


def validUTF8(data):
    for i in data:
        if i > 127 or i < -128:
            return False
    return True
