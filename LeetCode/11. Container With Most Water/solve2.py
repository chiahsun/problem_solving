class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        res = r * min(height[l], height[r])
        while l < r:
            if height[l] > height[r]:
                i = r-1
                while l < i and height[i] <= height[r]:
                    i -= 1
                r = i
            else:
                i = l+1
                while i < r and height[i] <= height[l]:
                    i += 1
                l = i
            res = max(res, (r-l) * min(height[l], height[r]))
        return res
