class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cand, cnt = None, 0
        for x in nums:
            if cnt == 0:
                cand = x; cnt = 1
            elif x == cand:
                cnt += 1
            else:
                cnt -= 1
        return cand
