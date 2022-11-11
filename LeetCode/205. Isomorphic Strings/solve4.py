class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d = {}
        for (a, b) in zip(s, t):
            if a in d: 
                if d[a] != b:
                    return False
            elif b in d.values():
                return False    
            d[a] = b
        return True
