class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for i in [i for i in range(1, len(s) // 2 + 1) if len(s) % i == 0]:
            if "".join(s[:i] * (len(s) // i)) == s:
                return len(s) != 1
        return False

