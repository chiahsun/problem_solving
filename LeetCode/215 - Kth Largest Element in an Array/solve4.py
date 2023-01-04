class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        def partition(lo, hi):
            pivot = nums[lo]
            # nums[:lt] < pivot, nums[gt:] > pivot
            i, lt, gt = lo, lo, hi+1
            while i < gt:
                a = nums[i]
                if a < pivot:
                    if lt != i:
                        nums[i], nums[lt] = nums[lt], nums[i]
                    lt += 1
                    i += 1
                elif a == pivot:
                    i += 1
                else:
                    gt -= 1
                    if i != gt:
                        nums[i], nums[gt] = nums[gt], nums[i]
            return lt, gt

        shuffle(nums)
        N = len(nums)
        k = N-k
        lo, hi = 0, N-1
        while True:
            lt, gt = partition(lo, hi)
            if lt <= k < gt:
                break
            if gt <= k:
                lo = gt
            else:
                hi = lt-1

        return nums[lt]

