class Solution {
  int minPathSum(List<List<int>> grid) {
    final M = grid.length, N = grid.first.length;
    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            if (i == 0 && k == 0) continue;
            if (i - 1 < 0)      grid[i][k] += grid[i][k-1];
            else if (k - 1 < 0) grid[i][k] += grid[i-1][k];
            else                grid[i][k] += min(grid[i][k-1], grid[i-1][k]);
        }
    }
    return grid.last.last;
  }
}
