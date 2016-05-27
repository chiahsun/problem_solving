class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        res = []
        carry = 0
        for i in range(max(len(a), len(b))+1):
            i += 1
            x = ord(a[-i]) - ord('0') if i <= len(a) else 0
            y = ord(b[-i]) - ord('0') if i <= len(b) else 0
            carry = carry + x + y
            if i != (max(len(a), len(b))+1) or carry:
                res.append("0" if carry % 2 == 0 else "1")
            carry = 0 if carry < 2 else 1
        return "".join(res[::-1])
