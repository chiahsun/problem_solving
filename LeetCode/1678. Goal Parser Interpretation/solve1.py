class Solution:
    def interpret(self, command: str) -> str:
        g = iter(command)
        ans = []
        for c in g:
            if c == 'G':
                ans.append('G')
            else:
                c2 = next(g)
                if c2 == 'a':
                    ans.append('al')
                    next(g)
                    next(g)
                else:
                    ans.append('o')
        return "".join(ans)
