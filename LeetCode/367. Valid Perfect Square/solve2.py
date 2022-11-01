class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        x, prev = num, num+1
        while prev - x >= 0.01:
            prev = x
            x = -x/2 + num/2/x + x
        return floor(x) ** 2 == num
