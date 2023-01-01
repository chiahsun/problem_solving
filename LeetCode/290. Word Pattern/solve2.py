class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        l1, l2, d = list(pattern), s.split(" "), dict()
        if len(l1) != len(l2):
            return False
        for i, pat in enumerate(l1):
            if pat in d:
                if d[pat] != l2[i]:
                    return False
            else:
                d[pat] = l2[i]
        return len(set(d.keys())) == len(set(d.values()))
