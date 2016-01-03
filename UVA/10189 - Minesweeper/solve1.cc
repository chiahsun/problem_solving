#include <cstdio>
#include <cstring>

const int M = 100+5;
char a[M][M];
int b[M][M];

const char MINE = '*';

const int dx[8] = {1,  1,  0, -1, -1, -1, 0, 1};
const int dy[8] = {0, -1, -1, -1,  0,  1, 1, 1};

int main() {
    int posField = 1;

    int nRow, nCol;
    while (scanf("%d%d", &nRow, &nCol) && nRow) {
        for (int posRow = 0; posRow < nRow; ++posRow) {
            scanf("%s", a[posRow]);
        }
        memset(b, 0, sizeof(b));

        for (int posRow = 0; posRow < nRow; ++posRow)
            for (int posCol = 0; posCol < nCol; ++posCol) {
                if (a[posRow][posCol] == MINE) {
                    for (int i = 0; i < 8; ++i) {
                        int x = posRow + dx[i];
                        int y = posCol + dy[i];

                        if (x >= 0 and x < nRow and y >= 0 and y < nCol) {
                            b[x][y] += 1;
                        }
                    }
                }
            }

        if (posField > 1)
            printf("\n");
        printf("Field #%d:\n", posField++);
        for (int posRow = 0; posRow < nRow; ++posRow) {
            for (int posCol = 0; posCol < nCol; ++posCol) {
                if (a[posRow][posCol] == MINE)
                    printf("*");
                else
                    printf("%d", b[posRow][posCol]);
            }
            printf("\n");
        }


    }
    return 0;
}
