class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = { }
        for i in range(len(nums)):
            cur = nums[i]
            if cur in d:
                if 2 * cur == target:
                    return [d[cur], i]
            else:
                d[cur] = i

        # d = { nums[i] : i for i in range(len(nums)) }

        for x in d:
            y = target - x
            if y in d:
                return [d[x], d[y]] if d[x] <= d[y] else [d[y], d[x]]

        return []


s = Solution()

print(s.twoSum([3, 2, 4], 6))
print(s.twoSum([3, 4, 4, 7], 8))
