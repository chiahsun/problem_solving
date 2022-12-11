class Solution:
    def calculate(self, s: str) -> int:
        nums, ops, i, N, digit_begin = [], [], 0, len(s), None
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
                    if ops and ops[-1] in ['*', '/']:
                        snd = nums.pop()
                        fst = nums.pop()
                        op = ops.pop()
                        if op == '*':
                            nums.append(fst * snd)
                        else:
                            nums.append(fst // snd)
        if ops:
            fst = nums[0]
            for i in range(len(ops)):
                snd = nums[i+1]
                op = ops[i]
                if op == '+':
                    fst = fst + snd
                else:
                    fst = fst - snd
            nums = [fst]
        return nums[0]
