class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans, N = [], min(len(word1), len(word2))
        for a, b in zip(word1, word2):
            ans.append(a)
            ans.append(b)
        if len(word1) > N:
            ans.extend(word1[N:])
        if len(word2) > N:
            ans.extend(word2[N:])
        return "".join(ans)
