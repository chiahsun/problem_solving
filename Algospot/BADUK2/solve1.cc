#include <cstdio>
#include <cstring>
#include <cstdlib>

const int M = 19+5;
int N, nBlack, nWhite;

char board[M][M];
bool visited[M][M];

const char EMPTY = ' ', WHITE = 'w', BLACK = 'b';

void read_as_color(int num, bool is_black) {
    int x, y;
    while (num--) {
        scanf("%d%d", &x, &y); 
        --x, --y;
        board[x][y] = (is_black) ? BLACK : WHITE;
    }
}

void dfs(int x, int y, int & region, bool & touch_w, bool & touch_b) {
    visited[x][y] = true;
    region += 1;

    const static int SIZE = 4;
    const static int dx[SIZE] = {1, -1, 0, 0};
    const static int dy[SIZE] = {0, 0, 1, -1};
    for (int i = 0; i < SIZE; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and nx < N and ny >= 0 and ny < N) {
            if (board[nx][ny] == WHITE) touch_w = true;
            else if (board[nx][ny] == BLACK) touch_b = true;
            else if (not visited[nx][ny]) dfs(nx, ny, region, touch_w, touch_b);
        }
    }
}

int main() {
    while (scanf("%d%d%d", &N, &nBlack, &nWhite) == 3) {
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k)
                board[i][k] = EMPTY;
        read_as_color(nBlack, true);
        read_as_color(nWhite, false);
#if 0
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < N; ++k)
                printf("%c", board[i][k]);
            printf("\n");
        }
#endif

        memset(visited, false, sizeof(visited));
        int region_white = 0, region_black = 0;
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k) {
                if (board[i][k] == EMPTY and not visited[i][k]) {
                    bool touch_w = false, touch_b = false;
                    int region = 0;
                    dfs(i, k, region, touch_w, touch_b);
                    if (not touch_w and touch_b) region_black += region;
                    else if (not touch_b and touch_w) region_white += region;
                }
            }
        if (region_black == region_white)
            printf("Draw\n");
        else
            printf("%s wins by %d\n", (region_black > region_white) ? "Black" : "White", abs(region_black-region_white));

    }

    return 0;
}
