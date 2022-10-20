import functools
import operator # https://docs.python.org/2/library/operator.html
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        digits = list(map(int, [*str(n)]))
        return functools.reduce(operator.mul, digits, 1) - functools.reduce(operator.add, digits, 0)
