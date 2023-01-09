class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res, N = [], len(words)
        for i in range(N):
            for k in range(N):
                if i != k and words[i] in words[k]:
                    res.append(words[i])
                    break
        return res
