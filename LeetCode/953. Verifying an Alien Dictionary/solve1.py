class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        d = { c: i for i, c in enumerate(order) }
        def my_cmp(s1, s2):
            N1, N2 = len(s1), len(s2)
            for i in range(min(N1, N2)):
                if d[s1[i]] > d[s2[i]]:
                    return 1
                elif d[s1[i]] < d[s2[i]]:
                    return -1
            return 1 if N1 > N2 else (0 if N1 == N2 else -1)
        res = sorted(words, key=cmp_to_key(my_cmp))
        return res == words
