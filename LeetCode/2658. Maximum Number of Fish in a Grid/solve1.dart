class Solution {
  int findMaxFish(List<List<int>> grid) {
    final M = grid.length, N = grid.first.length;
    int total = 0, res = 0;
    void floodfill(int r, int c) {
        total += grid[r][c];
        grid[r][c] = -grid[r][c];
        for (final [nr, nc] in [[r+1, c], [r-1, c], [r, c+1], [r, c-1]]) {
            if (nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] > 0) {
                floodfill(nr, nc);
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            if (grid[i][k] > 0) {
                total = 0;
                floodfill(i, k);
                res = max(res, total);
            }
        }
    }
    return res;
  }
}
