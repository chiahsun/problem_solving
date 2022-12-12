class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        def backtracking(nums, cur, res):
            if not nums:
                res.append(cur[:])
                return
            for i, n in enumerate(nums):
                if i != 0:
                    nums[0], nums[i] = nums[i], nums[0]
                cur.append(nums[0])
                backtracking(nums[1:], cur, res)
                cur.pop()
        cur, res = [], []
        backtracking(nums, cur, res)
        return res

