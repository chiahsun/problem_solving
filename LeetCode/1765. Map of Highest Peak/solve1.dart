class Solution {
  List<List<int>> highestPeak(List<List<int>> isWater) {
    final M = isWater.length, N = isWater.first.length, notAssigned = -1;
    List<List<int>> map = List.generate(M, (i) => List.generate(N, (k) => (isWater[i][k] == 1 ? 0 : notAssigned), growable: false), growable: false);
    List<List<int>> q = [for (int i = 0; i < M; ++i) for (int k = 0; k < N; ++k) [i, k]];
    q = q.where((e) => isWater[e[0]][e[1]] == 1).toList();
    List<List<int>> qNext = [];
    int cur = 0;
    while (!q.isEmpty) {
        ++cur;
        for (final e in q) {
            for (final [dx, dy] in [[1, 0], [-1, 0], [0, 1], [0, -1]]) {
                final nx = e[0] + dx, ny = e[1] + dy;
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[nx][ny] == notAssigned) {
                    map[nx][ny] = cur;
                    qNext.add([nx, ny]);
                }
            }
        }
        q = qNext; qNext = [];
    }
    return map;
  }
}
