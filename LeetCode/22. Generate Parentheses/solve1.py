class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def backtracking(open, left, cur):
            if left == 0:
                for _ in range(open):
                    cur.append(")")
                res.append("".join(cur))
                for _ in range(open):
                    cur.pop()
                return
            cur.append("(")
            backtracking(open+1, left-1, cur)
            cur.pop()
            if open > 0:
                cur.append(")")
                backtracking(open-1, left, cur)
                cur.pop()
        backtracking(0, n, [])
        return res
            
