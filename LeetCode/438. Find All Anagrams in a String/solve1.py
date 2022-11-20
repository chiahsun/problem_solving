class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        N = len(p)
        if len(s) < N:
            return []
        d = defaultdict(int)
        for c in p:
            d[c] -= 1
        for i in range(N):
            d[s[i]] += 1
        ans = [0] if all(k == 0 for k in d.values()) else []
        
        for i in range(N, len(s)):
            d[s[i]] += 1
            d[s[i-N]] -= 1
            if all(k == 0 for k in d.values()):
                ans.append(i-N+1)
        return ans

