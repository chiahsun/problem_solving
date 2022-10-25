class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        def words_gen(words):
            for word in words:
                for c in word:
                    yield c
        def peek(words):
            try:
                return next(words)
            except StopIteration:
                return None
        w1, w2 = words_gen(word1), words_gen(word2)
        for c1 in w1:
            c2 = peek(w2)
            if c2 is None or c1 != c2:
                return False
            
        return peek(w2) is None
