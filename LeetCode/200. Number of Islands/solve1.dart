class Solution {
  int numIslands(List<List<String>> grid) {
    final M = grid.length, N = grid[0].length;
    int res = 0;
    void dfs(int i, int k) {
        grid[i][k] = '0';
        if (i+1 < M && grid[i+1][k] == '1') dfs(i+1, k);
        if (i-1 >= 0 && grid[i-1][k] == '1') dfs(i-1, k);
        if (k+1 < N && grid[i][k+1] == '1') dfs(i, k+1);
        if (k-1 >= 0 && grid[i][k-1] == '1') dfs(i, k-1);
    }
    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            if (grid[i][k] == '1') {
                ++res;
                dfs(i, k);
            }
        }
    }
    return res;
  }
}
