#include <cstdio>
#include <cstring>

const int M = 100+5;
int board[M][M];
bool visited[M][M];

bool dfs(const int x, const int y, const int N) {
    visited[x][y] = true;
    if (x == N-1 and y == N-1)
        return true;
    int now = board[x][y];
    int nx = x+now, ny = y;
    if (nx >= 0 and nx < N and ny >= 0 and ny < N and not visited[nx][ny] and dfs(nx, ny, N))
        return true;
    nx = x, ny = y+now;
    return (nx >= 0 and nx < N and ny >= 0 and ny < N and not visited[nx][ny] and dfs(nx, ny, N));
}

int main() {
    int nCase, N;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k)
                scanf("%d", &board[i][k]);

        memset(visited, false, sizeof(visited));
        printf("%s\n", dfs(0, 0, N) ? "YES" : "NO");
    }
    return 0;
}
