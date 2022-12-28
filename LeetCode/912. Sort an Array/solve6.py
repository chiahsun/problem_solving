class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        shuffle(nums)
        
        def quick_sort(lo, hi):
            if lo >= hi:
                return
            lt, eq, gt, i = lo, lo, hi+1, lo
            pivot = nums[lo]
            while i < gt:
                if nums[i] == pivot:
                    nums[i], nums[eq] = nums[eq], nums[i]
                    eq += 1
                    i += 1
                elif nums[i] < pivot:
                    nums[i], nums[lt] = nums[lt], nums[i]
                    lt += 1
                    eq += 1
                    i += 1
                else:
                    gt -= 1
                    nums[i], nums[gt] = nums[gt], nums[i]
            quick_sort(lo, lt-1)
            quick_sort(gt, hi)
        quick_sort(0, len(nums)-1)
        return nums


