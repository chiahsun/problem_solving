class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        def sorted_str(s):
            return "".join(sorted([*s]))

        if len(s1) != len(s2) or sorted_str(s1) != sorted_str(s2):
            return False
        cnt = 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                cnt += 1
        return cnt <= 2
