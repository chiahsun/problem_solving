class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        h = sorted(heights)
        return sum(h[i] != heights[i] for i in range(len(h)))
