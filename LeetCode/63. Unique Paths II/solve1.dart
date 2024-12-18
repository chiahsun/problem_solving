class Solution {
  int uniquePathsWithObstacles(List<List<int>> obstacleGrid) {
    final M = obstacleGrid.length, N = obstacleGrid.first.length;
    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            obstacleGrid[i][k] = 1 - obstacleGrid[i][k];
            if ((i == 0 && k == 0) || obstacleGrid[i][k] == 0) continue;
            if (i-1 < 0)      obstacleGrid[i][k] = obstacleGrid[i][k-1];
            else if (k-1 < 0) obstacleGrid[i][k] = obstacleGrid[i-1][k];
            else              obstacleGrid[i][k] = obstacleGrid[i][k-1] + obstacleGrid[i-1][k];
        }
    }
    return obstacleGrid[M-1][N-1];
  }
}
