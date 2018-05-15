class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        for i in range(1, x+1):
            if (i+1) ** 2 > x:
                return i
        return -1

s = Solution()
print(s.mySqrt(2147395599))
