class Solution:
    def partition(nums, lo, hi):
        if lo >= hi:
            return lo

        pivot, i, j = nums[lo], lo + 1, hi
        while i < j:
            while i < j and nums[i] < pivot:
                i += 1
            while j > i and nums[j] >= pivot:
                j -= 1

            if i != j:
                nums[i], nums[j] = nums[j], nums[i]
        if nums[j] >= pivot:
            j -= 1
        if j != lo:
            nums[lo], nums[j] = nums[j], nums[lo]
        return j

    def findKthLargest(self, nums: List[int], k: int) -> int:
        shuffle(nums)
        N = len(nums)
        k = N - k
        lo, hi, j = 0, N - 1, -1
        while True:
            j = Solution.partition(nums, lo, hi)
            if j == k:
                break
            if j > k:
                hi = j - 1
            else:
                lo = j + 1
        return nums[j]

