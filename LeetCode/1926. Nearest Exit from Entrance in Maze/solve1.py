class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        M, N, q = len(maze), len(maze[0]), [entrance]
        maze[entrance[0]][entrance[1]] = "-"
        d = 0
        while q:
            qn = []
            for e in q:
                x, y = e[0], e[1]
                for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                    nx, ny = x+dx, y+dy
                    if nx >= 0 and nx < M and ny >= 0 and ny < N and maze[nx][ny] == ".":
                        if nx == 0 or nx == M-1 or ny == 0 or ny == N-1:
                            return d+1
                        else:
                            qn.append([nx, ny])
                            maze[nx][ny] = "-"
            d += 1
            q = qn
        return -1
