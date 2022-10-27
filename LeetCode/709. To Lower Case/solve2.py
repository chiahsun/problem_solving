class Solution:
    def toLowerCase(self, s: str) -> str:
        return "".join(map(lambda c: chr(ord(c) - ord('A') + ord('a')) if ord('A') <= ord(c) and ord(c) <= ord('Z') else c, list(s)))
