#include <cstdio>
#include <cstring>

const int M = 9;
const char W = 'O';
const char B = 'X';
const char D = '.';

char board[M+5][M+5];
bool visited[M][M];

void read_board() {
    for (int i = 0; i < M; ++i) {
        scanf("%s", board[i]);
    }
}

void print_board() {
    for (int i = 0; i < M; ++i)
        printf("%s\n", board[i]);
}
void search(const int x, const int y, int & cnt, bool & touchb, bool & touchw) {
    visited[x][y] = true;
    ++cnt;
    const int SZ = 4;
    const int dx[SZ] = {1, -1, 0, 0};
    const int dy[SZ] = {0, 0, 1, -1};
    for (int d = 0; d < SZ; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 and nx < M and ny >= 0 and ny < M) {
            if (board[nx][ny] == W) touchw = true;
            else if (board[nx][ny] == B) touchb = true;
            else if (not visited[nx][ny]) search(nx, ny, cnt, touchb, touchw);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        read_board();
        memset(visited, false, sizeof(visited));
//        print_board();
        int tb = 0, tw = 0, nb = 0, nw = 0;
        for (int i = 0; i < M; ++i)
            for (int k = 0; k < M; ++k) {
                if (board[i][k] == D and (not visited[i][k])) {
                    int cnt = 0;
                    bool touchb = false, touchw = false;
                    search(i, k, cnt, touchb, touchw);
                    if ((not touchb) and touchw) tw += cnt;
                    else if ((not touchw) and touchb) tb += cnt;
                } else if (board[i][k] == W) {
                    ++nw; 
                } else if (board[i][k] == B) {
                    ++nb;
                }
            }
        printf("Black %d White %d\n", tb+nb, tw+nw);
    }
    return 0;
}
