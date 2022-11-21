class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        end = len(s)
        while end > 0 and s[end-1] == " ":
            end -= 1
        start = end
        while start > 0 and s[start-1] != " ":
            start -= 1
        return end-start
