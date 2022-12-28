class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def insertion_sort(nums, lo, hi):
            for i in range(lo+1, hi+1):
                for k in range(i, 0, -1):
                    if nums[k-1] > nums[k]:
                        nums[k-1], nums[k] = nums[k], nums[k-1]
                    else:
                        break

        def quick_sort(nums, lo, hi):
            if lo >= hi:
                return
            if lo + 7 >= hi:
                insertion_sort(nums, lo, hi)
                return

            l, h, i = lo, hi, lo
            ms = [nums[lo], nums[(lo+hi)//2], nums[hi]]
            m = ms[0] ^ ms[1] ^ ms[2] ^ max(ms) ^ min(ms)
            while i <= h:
                if nums[i] < m:
                    if i != l and nums[i] != nums[l]:
                        nums[i], nums[l] = nums[l], nums[i]
                    l += 1; i += 1
                elif nums[i] == m:
                    i += 1
                else:
                    if i != h and nums[i] != nums[h]:
                        nums[i], nums[h] = nums[h], nums[i]
                    h -= 1
            quick_sort(nums, lo, l-1)
            quick_sort(nums, h+1, hi)

        shuffle(nums)
        quick_sort(nums, 0, len(nums)-1)
        return nums

        
