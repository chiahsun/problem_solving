#!/bin/python3

import sys

def stockmax(prices):
    # Complete this function
    dp = [0]
    max_profit = 0
    for price in prices:
        next_dp = [0] * (len(dp)+1)
        for i in range(0, len(next_dp)):
            next_dp[i] = -0x7FFFFFFF
            if i > 0:
                next_dp[i] = max(next_dp[i], dp[i-1] - price)
            for k in range(i, len(dp)):
                next_dp[i] = max(next_dp[i], dp[k] + price*(k-i))

            max_profit = max(max_profit, next_dp[i])
        dp = next_dp
        # print('Current:', price, ' dp: ', dp)
        
    return max_profit
    
if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        prices = list(map(int, input().strip().split(' ')))
        result = stockmax(prices)
        print(result)

