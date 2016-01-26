#include <cstdio>
#include <cstring>

const int M = 100+5;
int N;
int map[M][M];
char buf[500];
int cnt[M];

void dfs(int x, int y, int cur) {
    map[x][y] = 0;
    const int SZ = 4;
    const int dx[SZ] = {1, -1, 0, 0};
    const int dy[SZ] = {0, 0, 1, -1};
    for (int d = 0; d < SZ; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 1 and nx <= N and ny >= 1 and ny <= N and map[nx][ny] == cur)
            dfs(nx, ny, cur);
    }
}
int main() {
    while (scanf("%d", &N) == 1 and N) {
        while (getchar() != '\n') {}
        for (int i = 1; i <= N; ++i)
           for (int k = 1; k <= N; ++k)
              map[i][k] = N;
//        memset(map, N, sizeof(map)); // The left is not mentioned
        for (int cur = 1; cur < N; ++cur) {
            scanf("%[^\n]", buf); getchar();
            int pos = 0, len, x, y;
            while (sscanf(buf+pos, "%d%d%n", &x, &y, &len) == 2) {
                pos += len;
                map[x][y] = cur;
            }
        }

        memset(cnt, 0, sizeof(cnt)); 
        bool wrong = false;
        for (int i = 1; (not wrong) and i <= N; ++i)
            for (int k = 1; (not wrong) and k <= N; ++k) {
                int cur = map[i][k];
                if (cur) {
                    if (++cnt[cur] > 1) {
                        wrong = true;
                        break;
                    }
                    dfs(i, k, cur);
                }
            }
        printf("%s\n", wrong ? "wrong" : "good");
    }
    return 0;
}
