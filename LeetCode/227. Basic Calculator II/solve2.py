class Solution:
    def calculate(self, s: str) -> int:
        nums, ops, digit_begin, N = [], [], None, len(s)
        for i, c in enumerate(s):
            if c in ['+', '-', '*', '/']:
                ops.append(c)
            elif c == ' ':
                pass
            else:
                if digit_begin == None:
                    digit_begin = i
                if i+1 == N or s[i+1] not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                    nums.append(int(s[digit_begin: i+1]))
                    digit_begin = None
                    if ops and (ops[-1] == '*' or ops[-1] == '/'):
                        op, b, a = ops.pop(), nums.pop(), nums.pop()
                        nums.append(a * b if op == '*' else a // b)
                    elif len(ops) > 1:
                        if ops[0] == '-':
                            nums[1] = -nums[1]
                        nums = [nums[0] + nums[1], nums[2]]
                        ops = ops[1:]
        if ops:
            if ops[0] == '-':
                nums[1] = -nums[1]
            nums = [nums[0] + nums[1]]
        return nums[0]

