class Solution:
    def partition(nums, lo, hi):
        if lo >= hi:
            return lo

        mid = (lo+hi)//2
        a, b, c = nums[lo], nums[mid], nums[hi]
        pivot_value = a ^ b ^ c ^ max(a, b, c) ^ min(a, b, c)
        if pivot_value == b:
            nums[mid], nums[hi] = nums[hi], nums[mid]
        elif pivot_value == a:
            nums[hi], nums[lo] = nums[lo], nums[hi]

        pivot, i, j = nums[hi], lo, hi
        while i < j:
            while i < j and nums[i] < pivot:
                i += 1
            while j > i and nums[j] >= pivot:
                j -= 1

            if i != j:
                nums[i], nums[j] = nums[j], nums[i]

        if nums[i] != pivot:
            nums[hi], nums[i] = nums[i], nums[hi]
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

