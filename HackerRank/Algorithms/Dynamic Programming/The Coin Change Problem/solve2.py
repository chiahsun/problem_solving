#!/bin/python3

import sys

def getWays(n, c):
    coin_values = sorted(c)
    dp = [0 for _ in range(n+1)]
    dp[0] = 1
    
    for coin_value in coin_values:
        # After each iteration, we have dp[val]: the number of solution for val using coin_values <= coin_value 
        for i in range(0, n - coin_value+1):
            dp[i+coin_value] += dp[i]
    return dp[n]
    
n, m = map(int, input().strip().split(' '))
c = list(map(int, input().strip().split(' ')))
print(getWays(n, c))

