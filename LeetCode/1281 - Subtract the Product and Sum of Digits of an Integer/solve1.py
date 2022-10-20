import functools
import operator # https://docs.python.org/2/library/operator.html
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        digits = []
        while n > 0:
            digits.append(n % 10)
            n //= 10
        return functools.reduce(operator.mul, digits, 1) - functools.reduce(operator.add, digits, 0)
