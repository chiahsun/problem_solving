class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        min_dist = 20000
        ans = -1
        # https://stackoverflow.com/questions/12986996/conditional-for-in-python
        for i in (k for k in range(len(points)) if points[k][0] == x or points[k][1] == y):
            cur_dist = abs(points[i][0] - x) + abs(points[i][1] - y)
            if cur_dist < min_dist:
                min_dist = cur_dist
                ans = i
        return ans

