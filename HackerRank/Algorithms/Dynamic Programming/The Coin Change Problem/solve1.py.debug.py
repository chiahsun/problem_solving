#!/bin/python3

import sys


def getWays(n, c):
    table = {}
    coin_values = sorted(c)
    
    print('Coin values: ', coin_values)
        
    def getWaysImpl(value, max_coin_value_pos):
        if max_coin_value_pos < 0:
            return 0
        if value == 0:
            return 1
    
        max_coin_value = coin_values[max_coin_value_pos]
        print('Call ', value, max_coin_value_pos)
        if value < max_coin_value:
            if value < coin_values[0]:
                return 0
            while value < max_coin_value:
                max_coin_value_pos -= 1
                max_coin_value = coin_values[max_coin_value_pos]
            return getWaysImpl(value, max_coin_value_pos)
        
        if not value in table:
            table[value] = {}

        if not max_coin_value_pos in table[value]:
            a1 = getWaysImpl(value, max_coin_value_pos-1)
            a2 = getWaysImpl(value-max_coin_value, max_coin_value_pos)
            
            table[value][max_coin_value_pos] = a1 + a2
            print('  > (', value, ',', max_coin_value_pos , ') = (', value, ',', max_coin_value_pos-1, ') + (', value-max_coin_value, ', ', max_coin_value_pos,') : ', table[value][max_coin_value_pos], ' = ', a1, '+', a2)

        return table[value][max_coin_value_pos]
        
    # Complete this function
    return getWaysImpl(n, len(coin_values)-1)
    
    
    

n, m = input().strip().split(' ')
n, m = [int(n), int(m)]
c = list(map(int, input().strip().split(' ')))
# Print the number of ways of making change for 'n' units using coins having the values given by 'c'
ways = getWays(n, c)

print(ways)
