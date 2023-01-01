class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s, N = s.split(' '), len(pattern)
        if N != len(s): return False
        
        d1, d2 = dict(), dict()
        for i in range(N):
            a, b = pattern[i], s[i]
            ind1, ind2 = a in d1, b in d2
            if not ind1 or not ind2:
                if ind1 or ind2:
                    return False            
                d1[a] = d2[b] = i
            if d1[a] != d2[b]:
                return False
        return True
            
