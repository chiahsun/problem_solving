class Solution:
    def canJump(self, nums: List[int]) -> bool:
        N, res = len(nums), 0
        for i in range(N):
            if i <= res:
                res = max(res, i + nums[i])
        return res >= N-1
