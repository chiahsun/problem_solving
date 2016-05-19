import math

class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        k = k - 1
        return self.helper([x for x in range(1, n+1)], n, k)
        
    def helper(self, s, n, k):
        if n == 1 or k == 0:
            return ''.join([str(x) for x in s]);
        m = k // math.factorial(n-1)
        return str(s[m]) + self.helper(s[:m]+s[m+1:], n-1, k % math.factorial(n-1))


s = Solution()
print(s.getPermutation(1, 1))
print(s.getPermutation(2, 1))
print(s.getPermutation(2, 2))
print(s.getPermutation(3, 1))
print(s.getPermutation(3, 2))
print(s.getPermutation(3, 3))
print(s.getPermutation(3, 4))
print(s.getPermutation(3, 5))
print(s.getPermutation(3, 6))

