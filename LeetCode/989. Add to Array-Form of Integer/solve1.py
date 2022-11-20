class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        carry, pos = 0, len(num)-1
        while k > 0 or carry > 0:
            carry = carry + k % 10 + (num[pos] if pos >= 0 else 0)
            if pos < 0:
                num = [carry % 10] + num
            else:
                num[pos] = carry % 10
            k //= 10; pos -= 1; carry //= 10
        return num

