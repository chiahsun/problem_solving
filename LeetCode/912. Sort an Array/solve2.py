class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def quick_sort(A, lo, hi):
            if lo >= hi:
                return
            m, l, h = A[lo], lo+1, hi
            while l <= h:
                while l <= h and A[l] <= m:
                    l += 1
                while lo < h and A[h] >= m:
                    h -= 1
                if l < h:
                    A[l], A[h] = A[h], A[l]
                    l += 1; h -= 1
            A[lo], A[h] = A[h], A[lo]
            quick_sort(A, lo, h-1)
            quick_sort(A, l, hi)

        shuffle(nums)
        quick_sort(nums, 0, len(nums)-1)
        return nums

