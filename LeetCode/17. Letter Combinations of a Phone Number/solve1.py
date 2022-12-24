class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        A = [['a', 'b', 'c'], ['d', 'e', 'f'], ['g', 'h', 'i'], ['j', 'k', 'l'], ['m', 'n', 'o'], ['p', 'q', 'r', 's'], ['t', 'u', 'v'], ['w', 'x', 'y', 'z']]

        N, res = len(digits), []
        def backtracking(pos, cur):
            if pos == N:
                if cur:
                    res.append("".join(cur))
                return
            for c in A[int(digits[pos])-2]:
                cur.append(c)
                backtracking(pos+1, cur)
                cur.pop()
        backtracking(0, [])
        return res
