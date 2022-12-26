class Solution:
    def jump(self, nums: List[int]) -> int:
        N, cnt, l, r = len(nums), 0, 0, 0
        while r != N-1:
            nr = r
            for i in range(l, min(r+1, N)):
                nr = max(min(nums[i] + i, N-1), nr)
            l, r, cnt = r+1, nr, cnt+1
        return cnt
