class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        res = r * min(height[l], height[r])
        while l < r:
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
            res = max(res, (r-l) * min(height[l], height[r]))
        return res
