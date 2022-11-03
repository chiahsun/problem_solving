# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        return bisect.bisect_left(range(0, n+1), 1, key=lambda x: 1 if isBadVersion(x) else 0)
