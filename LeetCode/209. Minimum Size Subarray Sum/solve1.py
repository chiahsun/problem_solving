class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        N, begin, s = len(nums), 0, 0   
        res = N+1
        for i, n in enumerate(nums):
            s += n
            while s >= target and begin <= i:
                res = min(res, i-begin+1)
                s -= nums[begin]
                begin += 1

        return 0 if res > N else res

