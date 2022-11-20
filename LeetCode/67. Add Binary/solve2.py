class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = [int(d) for d in reversed(a)]
        b = [int(d) for d in reversed(b)]
        carry, c = 0, []
        for i in range(max(len(a), len(b))):
            carry += a[i] if i < len(a) else 0
            carry += b[i] if i < len(b) else 0
            c.append(carry % 2)
            carry >>= 1
            
        if carry > 0:
            c.append(carry)

        return "".join(map(str, reversed(c)))
