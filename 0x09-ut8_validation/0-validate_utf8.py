#!/usr/bin/python3


def validUTF8(data):
    try:
        bytes(data).decode("UTF-8")
        return True
    except ValueError as e:
        return False
