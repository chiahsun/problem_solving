class Solution:
    def nextGreaterElement(self, n: int) -> int:
        digits = []
        while n > 0:
            digits.append(n % 10)
            n //= 10
        for i in range(1, len(digits)):
            if digits[i] < digits[i-1]:
                for k in range(i):
                    if digits[k] > digits[i]:
                        digits[i], digits[k] = digits[k], digits[i]
                        digits[:i] = sorted(digits[:i], reverse=True)
                        res = 0
                        for d in reversed(digits):
                            res *= 10
                            res += d
                        return res if res <= 2147483647 else -1
        return -1
