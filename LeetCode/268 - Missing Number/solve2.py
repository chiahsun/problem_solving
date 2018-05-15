class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for x in nums:
            ans ^= x
        for i in range(len(nums)+1):
            ans ^= i
        return ans
