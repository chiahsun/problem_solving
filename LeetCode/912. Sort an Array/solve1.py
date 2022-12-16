class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def sink(nums, i, sz):
            while (l := 2*i+1) < sz:
                r = l+1
                max_val = max(nums[i], nums[l], nums[r] if r < sz else nums[i])
                nxt = l if nums[l] == max_val else (i if max_val == nums[i] else r)
                if nxt == i:
                    break
                nums[nxt], nums[i] = nums[i], nums[nxt]
                i = nxt

        # heapify nums
        N = len(nums)
        for i in reversed(range(N)):
            sink(nums, i, N)

        for i in reversed(range(N)):
            nums[i], nums[0] = nums[0], nums[i]
            sink(nums, 0, i)
            
        return nums

