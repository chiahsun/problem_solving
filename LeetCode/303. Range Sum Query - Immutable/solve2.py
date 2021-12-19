class NumArray(object):

    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.table = [nums[0] if nums else 0]
            
        for i in range(1, len(nums)):
            self.table.append(self.table[i-1] + nums[i])

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        table = self.table
        return table[j] - (table[i-1] if i-1 >= 0 else 0)

