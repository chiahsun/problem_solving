class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cnt = [0] * 3
        for n in nums:
            cnt[n] += 1
        prev = 0
        for i in range(3):
            for k in range(cnt[i]):
                nums[prev + k] = i
            prev += cnt[i]
        
