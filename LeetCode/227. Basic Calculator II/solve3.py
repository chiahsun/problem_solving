class Solution:
    def calculate(self, s: str) -> int:
        nums, ops, digit_begin, N, res = [], [], None, len(s), 0
        neg, fst, snd, op = False, 0, 0, '+'
        for i, c in enumerate(s):
            if c  == ' ':
                pass
            elif c in ['+', '-', '*', '/']:
                op = c
            else:
                if digit_begin is None:
                    digit_begin = i
                if i+1 == N or s[i+1] not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                    snd = int(s[digit_begin:i+1])
                    digit_begin = None
                    if op == '+':
                        res += fst; fst = snd
                    elif op == '-':
                        res += fst; fst = -snd
                    elif op == '*':
                        fst = fst * snd
                    else:
                        fst = fst // snd if fst >= 0 else -(-fst // snd)
                # Note that (-3) // 4 = -1 and - (3 // 4) = 0
                # print('fst: ', fst, ' op: ', op, ' res: ', res)
        return res + fst

