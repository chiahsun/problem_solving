class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        S, T = [], []
        def remove_or_append(l, c):
            if c != '#':
                l[0].append(c)
            elif l[0]:
                l[0].pop()

        for a in s:
            remove_or_append([S], a)
        for b in t:
            remove_or_append([T], b)
        
        return S == T
