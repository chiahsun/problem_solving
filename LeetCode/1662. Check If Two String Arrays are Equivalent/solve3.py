class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        def total_length(words):
            return sum(map(lambda s: len(s), words))

        if total_length(word1) != total_length(word2):
            return False

        r1, r2, c1, c2 = 0, 0, 0, 0
        while r1 < len(word1) and r2 < len(word2):
            if word1[r1][c1] != word2[r2][c2]:
                return False
            c1 += 1
            c2 += 1
            if c1 == len(word1[r1]):
                c1 = 0
                r1 += 1
            if c2 == len(word2[r2]):
                c2 = 0
                r2 += 1
            if r1 == len(word1) and r2 != len(word2):
                return False
            if r2 == len(word2) and r1 != len(word1):
                return False
            
        return True
