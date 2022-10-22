# 2
# 2^2 = 4
# 4^2 = 16
# 1^2 + 6^2 = 1 + 16 = 37
# 3^2 + 7^2 = 9 + 49 = 58
# 5^2 + 8^2 = 25 + 64 = 89
# 8^2 + 9^2 = 64 + 81 = 145
# 1^2 + 4^2 + 5^2 = 1 + 16 + 25 = 42
# 4^2 + 2^2 = 16 + 4 = 20
# 2^2 = 4
class Solution:
    def isHappy(self, n: int) -> bool:

        def run(n):
            return reduce(lambda acc, elem: acc + int(elem) ** 2, [*str(n)], 0)
        
        # Floyd's algorithm for loop detection
        slow, fast = n, n
        while fast != 1:
            slow, fast = run(slow), run(run(fast))
            if slow == fast and slow != 1:
                return False

        return True
