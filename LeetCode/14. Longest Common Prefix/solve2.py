class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        cnt = 0
        for i in range(min(map(len, strs))):
            if all(map(lambda s: s[i] == strs[0][i], strs)):
                cnt += 1
            else:
                break
        return strs[0][:cnt]

