class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res, N = set(), len(nums)
        def backtracking(pos, st):
            if pos == N:
                return
            cur = nums[pos]
            if not st or st[-1] <= cur:
                st.append(cur)
                tupled = tuple(st)
                if tupled not in res:
                    res.add(tupled)
                    backtracking(pos+1, st)
                st.pop()
            backtracking(pos+1, st)
        backtracking(0, [])
        return filter(lambda l: len(l) >= 2, list(res))


