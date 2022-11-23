class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        a = list(range(len(points)))
        a.sort(key=lambda x: points[x][0] ** 2 + points[x][1] ** 2)
        return [points[i] for i in a[:k]]
