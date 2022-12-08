class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        N = len(nums)
        res = nums[0] + nums[1] + nums[2]
        for i in range(N-2):
            j, k = i+1, N-1
            while j < k:
                cur = nums[i] + nums[j] + nums[k]
                if cur == target:
                    return target
                if abs(cur - target) < abs(res - target):
                    res = cur
                if cur > target:
                    k -= 1
                else:
                    j += 1

        return res
                
