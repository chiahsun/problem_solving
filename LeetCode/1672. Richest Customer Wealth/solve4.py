from functools import reduce
import operator

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ans = 0
        for row in accounts:
            ans = max(ans, reduce(operator.add, row))
        return ans
