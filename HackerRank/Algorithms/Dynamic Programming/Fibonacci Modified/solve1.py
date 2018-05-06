#!/bin/python3

import sys

def fibonacciModified(t1, t2, n):
    n -= 1
    # Complete this function
    while n > 0:
        t1, t2 = t2, (t1 + t2 ** 2)
        n -= 1
    return t1

if __name__ == "__main__":
    t1, t2, n = input().strip().split(' ')
    t1, t2, n = [int(t1), int(t2), int(n)]
    result = fibonacciModified(t1, t2, n)
    print(result)

