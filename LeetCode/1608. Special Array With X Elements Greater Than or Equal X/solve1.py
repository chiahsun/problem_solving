class Solution:
    def specialArray(self, nums: List[int]) -> int:
        # 3 5 -> 2
        # 0 0 3 4 4 -> 3
        for candidate in range(0, len(nums)+1):
            cnt = 0
            for n in nums:
                if n >= candidate:
                    cnt += 1
                if cnt > candidate:
                    break
            if cnt == candidate:
                return candidate
                
        return -1
