#include <cstdio>
#include <cstring>
#include <algorithm>

const int M = 100 + 5;
char a[M][M];
bool visited[M][M];
char buf[M];

void flood(int x, int y, const int & nRow, const int & nCol) {
    visited[x][y] = true;
    for (int i = std::max(0, x-1); i < std::min(x+2, nRow); ++i)
        for (int k = std::max(0, y-1); k < std::min(y+2, nCol); ++k) {
            if (a[i][k] == '@' and not visited[i][k])
                flood(i, k, nRow, nCol);
        }
}

int main() {
    int nRow, nCol;
    while (scanf("%d%d", &nRow, &nCol) == 2 && nRow) {
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < nRow; ++i) {
            scanf("%s", a[i]);
        }
        int cnt = 0;
        for (int i = 0; i < nRow; ++i) {
            for (int k = 0; k < nCol; ++k) {
                if (a[i][k] == '@' and (not visited[i][k])) {
                    cnt += 1;
                    flood(i, k, nRow, nCol);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
