class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return chr(reduce(lambda acc, c: acc ^ ord(c), chain(s, t), 0))
