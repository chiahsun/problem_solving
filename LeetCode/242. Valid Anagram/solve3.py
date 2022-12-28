class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d1, d2 = defaultdict(int), defaultdict(int)
        for a in s:
            d1[a] += 1
        for b in t:
            d2[b] += 1
        return d1 == d2
