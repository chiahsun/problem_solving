class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        res = 0
        for i in range(len(strs[0])):
            for k in range(1, len(strs)):
                if strs[k][i] < strs[k-1][i]:
                    res += 1
                    break
        return res

