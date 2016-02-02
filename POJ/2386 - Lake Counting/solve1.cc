#include <cstdio>
#include <cstring>

const int M = 100+5;
char field[M][M];
char buf[M];

int nRow, nCol;
bool visited[M][M];

void dfs(int x, int y) {
    visited[x][y] = true;
    static const int SZ = 8;
    static int dx[SZ] = {1, 1, 1, 0, 0, -1, -1, -1};
    static int dy[SZ] = {1, 0, -1, 1, -1, 1, 0, -1};
    for (int d = 0; d < SZ; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 and nx < nRow and ny >= 0 and ny < nCol and field[nx][ny] == 'W' and (not visited[nx][ny]))
            dfs(nx, ny);
    }
}

int main() {
    while (scanf("%d%d", &nRow, &nCol) == 2) {
        for (int i = 0; i < nRow; ++i) {
            scanf("%s", buf);
            for (int k = 0; k < nCol; ++k)
                field[i][k] = buf[k];
        }

        memset(visited, false, sizeof(visited));

        int nPound = 0;
        for (int i = 0; i < nRow; ++i)
            for (int k = 0; k < nCol; ++k)
                if (not visited[i][k] and field[i][k] == 'W') {
                    ++nPound;
                    dfs(i, k);
                }

        printf("%d\n", nPound);

    }
    return 0;
}
