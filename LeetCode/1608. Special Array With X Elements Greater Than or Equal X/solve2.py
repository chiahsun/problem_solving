class Solution:
    def specialArray(self, nums: List[int]) -> int:
        # 3 5 -> 2
        # 2 1

        # 0 0 3 4 4 -> 3
        # 5 4 3 2 1
        
        # 3 3 3 3 -> -1
        # 4 3 2 1
        N = len(nums)
        nums.sort()
        for i in range(N):
            if (target := N-i) <= nums[i]:
                if i == 0 or nums[i-1] < target:
                    return target            
        return -1
