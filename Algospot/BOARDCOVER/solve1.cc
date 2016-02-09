#include <cstdio>
#include <cstring>

const bool debug =  false;

const int M = 20+5;
char board[M][M];

int nRow, nCol;

const static int SZ = 12;
const static int dx[SZ][3] = {{0, 1, 0}, {0, 1, 0}, {0, -1, 0}, {0, -1, 0}
                            , {0, 0, 1}, {0, 0, -1}, {0, 0, 1}, {0, 0, -1}
                            , {0, 1, 1}, {0, -1, -1}, {0, 1, 1}, {0, -1, -1}};
const static int dy[SZ][3] = {{0, 0, -1}, {0, 0, 1}, {0, 0, -1}, {0, 0, 1}
                            , {0, -1, -1}, {0, -1, -1}, {0, 1, 1}, {0, 1, 1}
                            , {0, 0, -1}, {0, 0, -1}, {0, 0, 1}, {0, 0, 1}};

void print_board(int nEmpty, int original_nEmpty) {
    for (int i = 0; i < nRow; ++i) {
        for (int k = 0; k < original_nEmpty - nEmpty; ++k) printf(" ");
        printf("%s\n", board[i]);
    }
//    printf("nEmpty : %d\n", nEmpty);
}

void fill_board(int x, int y, int d, char c) {
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[d][i];
        int ny = y + dy[d][i];
        board[nx][ny] = c;
    }
}

void dfs(int x, int y, int nEmpty, int & cnt, const int & original_nEmpty) {
    for (int d = 0; d < SZ; ++d) {
        bool ok = true;
        for (int i = 0; i < 3; ++i) {
            int nx = x + dx[d][i];
            int ny = y + dy[d][i];
            if (not (nx >= 0 and nx < nRow and ny >= 0 and ny < nCol and board[nx][ny] == '.')) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (nEmpty == 3) {
                ++cnt;
                break;
            }
            fill_board(x, y, d, '@');
            if (debug) {
                printf("now %d %d\n", x, y);
                print_board(nEmpty, original_nEmpty);
            }

            bool start = false;
            for (int i = x; (not start) and i < nRow; ++i)
                for (int k = (i == x) ? y+1 : 0; (not start) and k < nCol; ++k) {
                    if (board[i][k] == '.') {
                        if (debug)
                            printf("try %d %d \n\n", i, k);
                        dfs(i, k, nEmpty-3, cnt, original_nEmpty);
                        start = true;
                    } else {
                        if (debug)
                            printf("(bypass %d %d)\n", i, k);
                    }
                }

            fill_board(x, y, d, '.');
        }
    }
}

int main() {
    int nCase;
    scanf("%d", &nCase);

#if 0
    nRow = nCol = 3;
    for (int i = 0; i < 3; ++i) {
        for (int k = 0; k < 3; ++k)
            board[i][k] = '.';
        board[i][3] = '\0';
    }
    for (int i = 0; i < SZ; ++i) {
        fill_board(1, 1, i, '@');
        print_board(9-3);
        fill_board(1, 1, i, '.');
    }
#endif

#if 1 
    while (nCase--) {
        scanf("%d%d", &nRow, &nCol);
        int nEmpty = 0;
        for (int i = 0; i < nRow; ++i) {
            scanf("%s", board[i]);
            for (int k = 0; k < nCol; ++k)
                if (board[i][k] == '.')
                    ++nEmpty;
        }
        int cnt = 0;
        if (nEmpty % 3 == 0) {
            bool start = false;
            for (int i = 0; not start and i < nRow; ++i)
                for (int k = 0; not start and k < nCol; ++k) {
                    if (board[i][k] == '.') {
                        dfs(i, k, nEmpty, cnt, nEmpty);
                        start = true;
                    }
                }
        }
        printf("%d\n", cnt);
    }
#endif

    return 0;
}
