class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        N, res = len(candidates), []
        def backtracking(cur, left, pos):
            if left == 0:
                res.append(cur[:])
                return
            i = pos
            while i < N:
                if candidates[i] > left:
                    break
                a = candidates[i]
                cur.append(a)
                backtracking(cur, left-a, i+1)
                cur.pop()
                while i < N and candidates[i] == a:
                    i += 1
                
        backtracking([], target, 0)
        return res
