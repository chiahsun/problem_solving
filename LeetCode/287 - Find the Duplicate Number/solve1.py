class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        k = 0
        while True:
            i = nums[i]
            k = nums[nums[k]]
            if i == k:
                break
        i = 0
        while True:
            i = nums[i]
            k = nums[k]
            if i == k:
                break
        return i
