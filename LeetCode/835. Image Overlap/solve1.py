class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        N = len(img1)
        ans = 0
        for i in range(-N+1, N):
            for k in range(-N+1, N):
                cur = 0
                for r in range(max(0, -i), min(N, N-i)):
                    x = i+r
                    for c in range(max(0, -k), min(N, N-k)):
                        y = k+c
                        if img1[x][y] == 1 and img1[x][y] == img2[r][c]:
                            cur += 1
                ans = max(ans, cur)
        return ans
