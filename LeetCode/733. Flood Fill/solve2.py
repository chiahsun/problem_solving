class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        ori_color, NR, NC = image[sr][sc], len(image), len(image[0])
        def dfs(r, c):
            image[r][c] = color
            for dr, dc in zip([1, -1, 0, 0], [0, 0, 1, -1]):
                nr, nc = r+dr, c+dc
                if nr >= 0 and nr < NR and nc >= 0 and nc < NC and image[nr][nc] == ori_color:
                    dfs(nr, nc)
        if color != ori_color:
            dfs(sr, sc)
        return image
