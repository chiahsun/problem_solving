class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = strs[0]
        for i in range(1, len(strs)):
            s = strs[i]
            res = res[:len(s)]
            for k, c in enumerate(res):
                if c != s[k]:
                    res = res[:k]
                    break
            if not res:
                break
        return res
