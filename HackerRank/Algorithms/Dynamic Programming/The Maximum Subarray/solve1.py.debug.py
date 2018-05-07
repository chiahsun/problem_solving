#!/bin/python3

import sys

def maxSubarray(arr):
    # Complete this function
    def get_max_from_subsequences(arr):
        max_sum = cur_sum = 0 if not arr else arr[0]
        for a in arr[1:]:
            max_sum = max(max_sum, max_sum + a, a)
            print('a:', a, 'max sum:', max_sum)
        return max_sum

    def get_max_from_subarrays(arr):
        max_sum, cur_sum = 0 if not arr else arr[0], 0
        for a in arr:
            cur_sum += a
            cur_sum = max(cur_sum, a)
            max_sum = max(max_sum, cur_sum)
            print('a:', a, 'cur_sum:', cur_sum, '   max_sum:', max_sum)
        return max_sum
            
    return [get_max_from_subarrays(arr), get_max_from_subsequences(arr)]
            

if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        result = maxSubarray(arr)
        print (" ".join(map(str, result)))
