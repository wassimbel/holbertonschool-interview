#!/usr/bin/python3

import sys


def print_metrics(status_code, file_size):
    """ reads stdin line by line and computes metrics
        and prints file_size and status """

    print("File size: {}".format(file_size))
    for key, value in sorted(status_code.items()):
        if value != 0:
            print("{}: {}".format(key, value))


def compute_metrics():
    file_size = 0
    i = 0
    status_code = {"200": 0,
               "301": 0,
               "400": 0,
               "401": 0,
               "403": 0,
               "404": 0,
               "405": 0,
               "500": 0}

    try:
        for j in sys.stdin:
            metrics = j.split()

            if len(metrics) > 2:
                i += 1
                if i <= 10:
                    file_size += int(metrics[-1])
                    status = metrics[-2]

                    if (status in status_code.keys()):
                        status_code[status] += 1

                if (i == 10):
                    print_metrics(status_code, file_size)
                    i = 0

    except KeyboardInterrupt:
        print_metrics(status_code, file_size)
    finally:
        print_metrics(status_code, file_size)


if __name__ == '__main__':
    compute_metrics()
