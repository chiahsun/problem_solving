class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur = None
        count = 0
        N = len(nums)
        for i in range(N):
            x = nums[i]
            if count == 0:
                cur = x
                count = 1
            else:
                count += (1 if x == cur else -1)
            if count > N-i-1:
                return cur
                
        return cur
        
