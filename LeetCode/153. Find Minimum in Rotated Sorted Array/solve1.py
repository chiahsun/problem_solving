class Solution:
    def findMin(self, nums: List[int]) -> int:
        N, first = len(nums), nums[0]
        if N == 1 or first < nums[N-1]:
            return first
        # 4 5 6 7 0 1 2 
        # 0 0 0 0 1 1 1
        pos = bisect_left(nums, 1, key=lambda x: 1 if x < first else 0)
        return nums[pos]
