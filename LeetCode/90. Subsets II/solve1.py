class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res, N = [], len(nums)
        def backtracking(pos, cur):
            if pos == N:
                res.append(cur[:])
                return
            a = nums[pos]
            cur.append(a)
            backtracking(pos+1, cur)
            cur.pop()
            while pos < N and nums[pos] == a:
                pos += 1
            backtracking(pos, cur)
        backtracking(0, [])
        return res
