class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        s = set()
        for x in nums:
            if x in s:
                s.remove(x)
            else:
                s.add(x)
            
        while len(s) < 2:
            s.append(0)
            
        return list(s)
