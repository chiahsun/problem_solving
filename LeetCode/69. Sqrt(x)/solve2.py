class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        a = x
        while a > 1:
            d = (a**2 - x)/2/a
            a = a - d
            if a - int(a) > d or d < 1E-9:
                break
        return int(a)
