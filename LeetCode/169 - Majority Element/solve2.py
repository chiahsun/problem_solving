class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur = None
        count = 0
        for x in nums:
            if count == 0:
                cur = x
                count = 1
            else:
                count += (1 if x == cur else -1)
        return cur
        
