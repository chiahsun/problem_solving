from bisect import bisect_left	

class Solution(object):
    """
    Reference
      1. https://gist.github.com/ericremoreynolds/2d80300dabc70eebc790
    """
    class KeyList(object):
        def __init__(self, v, key):
            self.v = v
            self.key = key

        def __len__(self):
            return len(self.v)

        def __getitem__(self, i):
            return self.key(self.v[i])


    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        v = [ [nums[i], i] for i in range(len(nums)) ]
        v.sort(key=lambda pr: pr[0])

        for i in range(len(v)):
            x = v[i][0]
            y = target - x
            pos = 0
            if y < x:
                pos = bisect_left(self.KeyList(v, lambda x: x[0]), y, 0, x)
            else:
                pos = bisect_left(self.KeyList(v, lambda x: x[0]), y, i+1, len(v))
            if pos < len(v) and v[pos][0] == y and pos != i:
                a, b = v[pos][1], v[i][1]
                return [a, b] if a <= b else [b, a]
        return []


s = Solution()
print(s.twoSum([3, 2, 4], 6))
print(s.twoSum([2, 7, 11, 15], 9))

