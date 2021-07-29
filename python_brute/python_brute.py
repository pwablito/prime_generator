#!/usr/bin/env python3

import math
import sys


def is_prime(number):
    for test_val in range(2, int(math.sqrt(number)) + 1):
        if number % test_val == 0:
            return False
    return True


if __name__ == '__main__':
    try:
        test_space = int(sys.argv[1])
    except:
        print("Usage: <path_to_program> <int:test_space>")
        exit(1)
    for number in range(2, test_space):
        if is_prime(number):
            print(number)
