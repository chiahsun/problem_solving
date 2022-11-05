class Solution:
    def specialArray(self, nums: List[int]) -> int:
        # 3 5 -> 2

        # 0 0 3 4 4 -> 3

        # 3 3 3 3 -> -1
        N = len(nums)
        nums.sort()
        for i in range(N+1):
            pos = bisect.bisect_left(nums, i)
            if N - pos == i:
                return i
        return -1
