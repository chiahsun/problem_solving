class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        N = len(nums)
        res = nums[0] + nums[1] + nums[2]
        for i in range(0, N-2):
            for k in range(i+1, N-1):
                other = target - nums[i] - nums[k]
                pos = bisect_left(nums, other, k+1, N)
                if k+1 <= pos < N and nums[pos] == other:
                    res = target
                    break
                if pos-1 >= k+1:
                    if abs(res - target) > abs(nums[i] + nums[k] + nums[pos-1] - target):
                        res = nums[i] + nums[k] + nums[pos-1]
                if pos < N:
                    if abs(res - target) > abs(nums[i] + nums[k] + nums[pos] - target):
                        res = nums[i] + nums[k] + nums[pos]
        return res
                
