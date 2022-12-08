class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        begin, d, res = 0,  defaultdict(int), 0
        for i, c in enumerate(s):
            d[c] += 1
            while d[c] == 2:
                d[s[begin]] -= 1
                begin += 1
            res = max(res, i-begin+1)
        return res

