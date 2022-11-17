class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        for i in reversed(range(len(digits))):
            carry += digits[i]
            digits[i] = carry % 10
            carry //= 10
            if carry == 0:
                break
        return digits if carry == 0 else [1] + digits
