class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        #print('Compute', x)
        a = x
        while a > 1:
            d = (a**2 - x)/2/a
            a = a - d
            print('a:', a, 'd:', d)
            if a - int(a) > d or d < 1E-9:
                break
        return int(a)

s = Solution()
print(s.mySqrt(1))
print(s.mySqrt(2))
print(s.mySqrt(4))
#print(s.mySqrt(5))
#print(s.mySqrt(37))
#print(s.mySqrt(104))
#print(s.mySqrt(1001))
#print(s.mySqrt(2147395599))
#print(s.mySqrt(5))
