class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        def sink(nums, i, sz):
            while (l := 2*i+1) < sz:
                r = l+1
                max_val = max(nums[i], nums[l], nums[r] if r < sz else nums[i])
                nxt = i if max_val == nums[i] else (l if max_val == nums[l] else r)
                if nxt == i:
                    break
                nums[i], nums[nxt] = nums[nxt], nums[i]
                i = nxt
        
        N = len(nums)
        for i in reversed(range(N)):
            sink(nums, i, N)
        
        for i in reversed(range(N)):
            k -= 1
            if k == 0:
                break
            nums[0], nums[i] = nums[i], nums[0]
            sink(nums, 0, i)
            
        return nums[0]

