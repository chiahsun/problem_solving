class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s, t = sorted(s), sorted(t)
        for a, b in zip(s, t):
            if a != b:
                return b
        
        return t[-1]
