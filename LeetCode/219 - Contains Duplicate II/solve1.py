class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if len(nums) <= 1 or k <= 0:
            return False
            
        dict = {}
        for i in range(len(nums)):
            cur = nums[i]
            if not cur in dict:
                dict[cur] = i
            elif i - dict[cur] <= k:
                return True
            else:
                dict[cur] = i
        return False
