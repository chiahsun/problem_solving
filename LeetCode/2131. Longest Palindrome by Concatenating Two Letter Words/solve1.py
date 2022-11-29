class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        same_words = 0
        symmetric_words = 0
        d = defaultdict(int)
        for word in words:
            if word[0] == word[1]:
                if d[word] > 0:
                    d[word] -= 1
                    same_words -= 1
                    symmetric_words += 1
                else:
                    d[word] += 1
                    same_words += 1
            else:
                wd = word[1] + word[0]
                if d[wd] > 0:
                    d[wd] -= 1
                    symmetric_words += 1
                else:
                    d[word] += 1
        return symmetric_words * 4 + (2 if same_words > 0 else 0)
