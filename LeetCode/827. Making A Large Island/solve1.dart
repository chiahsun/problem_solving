class Solution {
  int largestIsland(List<List<int>> grid) {
    final M = grid.length, N = grid.first.length;
    List<List<int>> islandId = List.generate(M, (i) => List.filled(N, 0), growable: false);
    List<int> islandSize = [0];

    void floodfill() {
        int size = 0;

        void dfs(int id, int x, int y) {
            islandId[x][y] = id;
            ++size;
            for (final [nx, ny] in [[x+1, y], [x-1, y], [x, y+1], [x, y-1]]) {
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == 1 && islandId[nx][ny] == 0) {
                    dfs(id, nx, ny);
                }
            }
        }

        int id = 1;
        for (int i = 0; i < M; ++i) {
            for (int k = 0; k < N; ++k) {
                if (grid[i][k] == 1 && islandId[i][k] == 0) {
                    size = 0;
                    dfs(id++, i, k);
                    islandSize.add(size);
                }
            }
        }
    }

    floodfill();
    int res = max(islandSize.reduce((accu, elem) => max(accu, elem)), 1);

    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            if (grid[i][k] == 0) {
                List<int> connectedId = [];
                for (final [x, y] in [[i+1, k], [i-1, k], [i, k+1], [i, k-1]]) {
                    if (x >= 0 && x < M && y >= 0 && y < N && islandId[x][y] > 0) {
                        final id = islandId[x][y];
                        if (!connectedId.contains(id))
                            connectedId.add(id);
                    }
                }
                res = max(res, connectedId.fold(1, (accu, elem) => accu + islandSize[elem]));
            }
        }
    }

    return res;
  }
}
