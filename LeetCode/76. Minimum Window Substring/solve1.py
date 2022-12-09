class Solution:
    def minWindow(self, s: str, t: str) -> str:
        sf, tf = defaultdict(int), defaultdict(int)
        for c in t:
            tf[c] += 1
        begin = 0
        res = (0, len(s)+1)
        for i, c in enumerate(s):
            sf[c] += 1
            if all(sf[c] >= tf[c] for c in tf):
                while begin < i and (s[begin] not in tf or sf[s[begin]] > tf[s[begin]]):
                    sf[s[begin]] -= 1
                    begin += 1
                if i+1 - begin < res[1] - res[0]:
                    res = (begin, i+1)
        return "" if res[1] > len(s) else s[res[0]:res[1]]

