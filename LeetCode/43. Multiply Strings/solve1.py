class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        res = [0] *  (len(num1) + len(num2) - 1)
        for i, a in enumerate(reversed(num1)):
            carry, pos = 0, 0
            for k, b in enumerate(reversed(num2)):
                pos = i + k
                carry = carry + int(a) * int(b) + res[pos]
                res[pos] = carry % 10
                carry //= 10
            while carry > 0:
                pos += 1
                digit = carry % 10; carry //= 10
                if pos == len(res):
                    res.append(digit)
                else:
                    res[pos] = digit
                
        return "".join(map(str, reversed(res)))


