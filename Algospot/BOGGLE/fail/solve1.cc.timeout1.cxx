#include <cstdio>

const int M = 5+5;
char board[M][M];

char buf[50];
char query[50];

bool dfs(int x, int y, int pos, int len) {
    if (pos == len) return true;
    if (board[x][y] != query[pos]) return false;

    const int SZ = 8;
    static const int dx[SZ] = {1, 1, 1, 0, 0, -1, -1, -1};
    static const int dy[SZ] = {1, 0, -1, 1, -1, 1, 0, -1};

    for (int i = 0; i < SZ; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and nx < 5 and ny >= 0 and ny < 5 and dfs(nx, ny, pos+1, len))
            return true;
    }
    return false;
}

int main() {
    int nCase, nQuery;

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &nCase);

    while (nCase--) {
        for (int i = 0; i < 5; ++i)
            fgets(board[i], sizeof(board[i]), stdin);
#if 0
        for (int i = 0; i < 5; ++i)
            printf("%s", board[i]);
#endif
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &nQuery);
        while (nQuery--) {
            int len;
            fgets(buf, sizeof(buf), stdin);
            sscanf(buf, "%s%n", query, &len);

            bool found = false;
            for (int i = 0; not found and i < 5; ++i)
                for (int k = 0; not found and k < 5; ++k) {
                    if (dfs(i, k, 0, len))
                        found = true;
                }
            printf("%s %s\n", query, found ? "YES" : "NO");

        }
    }
    return 0;
}
