#!/bin/python3

import sys

def stockmax(prices):
    profit = 0
    last = 0
    # Complete this function
    for i in range(len(prices)-1, -1, -1):
        cur = prices[i]
        if cur < last:
            profit += (last - cur)
        elif cur > last:
            last = cur
        
    return profit
    
if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        prices = list(map(int, input().strip().split(' ')))
        result = stockmax(prices)
        print(result)


