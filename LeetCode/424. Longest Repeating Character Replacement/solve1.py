class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        d = defaultdict(int)
        def get_left():
            return sum(d.values()) - max(d.values())
        start, ans = 0, 0
        for i in range(len(s)):
            d[s[i]] += 1
            while get_left() > k:
                d[s[start]] -= 1
                start += 1
            ans = max(ans, i-start+1)
        return ans
