class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = []
        g1, g2 = iter(word1), iter(word2)
        for c in g1:
            ans.append(c)
            try:
                c = next(g2)
                ans.append(c)
            except:
                break
        for c in g1:
            ans.append(c)
        for c in g2:
            ans.append(c)
        return "".join(ans)
