// https://en.wikipedia.org/wiki/Disjoint-set_data_structure
class UF {
    List<int> parents = [], sizes = [];

    UF(int N) {
        parents = List.generate(N, (i) => i, growable: false);
        sizes = List.filled(N, 1);
    }

    int find(x) {
        while (parents[x] != x) {
            int parent = parents[x];
            parents[x] = parents[parent];
            x = parent;
        }
        return x;
    }

    int union(x, y) {
        int rx = find(x), ry = find(y);
        if (sizes[rx] < sizes[ry]) {
            (rx, ry) = (ry, rx);
        }
        sizes[rx] += sizes[ry];
        parents[ry] = rx;

        parents[x] = rx;
        parents[y] = rx;
        return rx;
    }

    int size(x) => sizes[x];
}

class Solution {
  int countServers(List<List<int>> grid) {
    final M = grid.length, N = grid.first.length;
    UF uf = UF(M * N);

    int getId(int x, int y) => N*x + y;

    for (int i = 0; i < M; ++i) {
        int firstId = -1;
        for (int k = 0; k < N; ++k) {
            if (grid[i][k] == 1) {
                if (firstId == -1) firstId = getId(i, k);
                else               uf.union(firstId, getId(i, k));
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        int firstId = -1;
        for (int k = 0; k < M; ++k) {
            if (grid[k][i] == 1) {
                if (firstId == -1) firstId = getId(k, i);
                else               uf.union(firstId, getId(k, i));
            }
        }
    }

    List<int> singles = [];
    for (int i = 0; i < M*N; ++i) {
        int root = uf.find(i);
        if (uf.size(root) == 1) {
            singles.add(root);
        }
    }

    return M*N - singles.length;
  }
}
