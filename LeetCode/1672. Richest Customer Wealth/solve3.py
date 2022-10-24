import numpy as np
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return np.array(accounts).sum(axis=1).max()
