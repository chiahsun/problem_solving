class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        # 1 1 2 2 3 3: []
        # 1 1 1 2 2 2: [1 2]
        nums.sort()
        i, target_cnt, ans = 0, len(nums) // 3, []
        while i < len(nums):
            cur, cnt = nums[i], 0
            while i < len(nums) and nums[i] == cur:
                i += 1; cnt += 1
            if cnt > target_cnt:
                ans.append(cur)
        return ans
