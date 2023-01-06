class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        cnt, a, b = 0, strs[0], strs[-1]
        for i in range(min(len(a), len(b))):
            if a[i] == b[i]:
                cnt += 1
            else:
                break
        return a[:cnt]
