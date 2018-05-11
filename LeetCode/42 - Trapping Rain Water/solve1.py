class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0
        N = len(height)
        left = [0] * N
        right = [0] * N
        ml = left[0] = height[0]
        mr = right[N-1] = height[N-1]
        for i in range(1, N-1):
            left[i] = ml = max(height[i], ml)
            right[N-i-1] = mr = max(height[N-i-1], mr)
        total = 0
        for i in range(1, N-1):
            total += (min(left[i], right[i]) - height[i])
        return total

