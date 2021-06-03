#!/usr/bin/python3
    """  reads stdin line by line and computes metrics """


import sys


if __name__ == '__main__':

    def print_metrics():
        """  reads stdin line by line and computes metrics
             Prints total File Size and number of lines of each status code """

        print("File size: {}".format(file_size))
        for keys in sorted(status_code.keys()):
            if status_code[keys] != 0:
                print("{}: {}".format(keys, status_code[keys]))

    status_code = {"200": 0,
                   "301": 0,
                   "400": 0,
                   "401": 0,
                   "403": 0,
                   "404": 0,
                   "405": 0,
                   "500": 0}
    i = 0
    file_size = 0

 try:
        for j in sys.stdin:
            i += 1
            metrics = j.split()
            try:
                file_size += int(metrics[-1])
            except:
                pass
            try:
                status = metrics[-2]
                if status in status_code:
                    status_code[status] += 1
            except:
                pass
            if count % 10 == 0:
                print_metrics()
        print_metrics()
    except KeyboardInterrupt:
        print_metrics()
        raise
