class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        def backtracking(left: int, candidates: List[int], cur: List[int], res: []):
            for i, c in enumerate(candidates):
                if c == left:
                    res.append(cur + [c])
                elif c < left:
                    cur.append(c)
                    backtracking(left-c, candidates[i:], cur, res)
                    cur.pop()
        cur, res = [], []
        backtracking(target, candidates, cur, res)
        return res
