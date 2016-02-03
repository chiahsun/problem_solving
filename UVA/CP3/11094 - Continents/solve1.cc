#include <cstdio>
#include <algorithm>

char map[20+5][20+5];
const int SZ = 4;
const int dx[SZ] = {1, -1, 0, 0};
const int dy[SZ] = {0, 0, 1, -1};

char land = 'l';
char water = 'w';
int nRow, nCol;

int replace(int x, int y) {
    map[x][y] = water;
    int cnt = 1;
    for (int i = 0; i < SZ; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and nx < nRow and ny >= 0 and ny < nCol and map[nx][ny] == land)
            cnt += replace(nx, ny);
    }
    if (y+1 == nCol and map[x][0] == land and nCol != 1)
        cnt += replace(x, 0);
    if (y == 0 and map[x][nCol-1] == land and nCol != 1)
        cnt += replace(x, nCol-1);
    return cnt;
}


int main() {
    while (scanf("%d%d", &nRow, &nCol) == 2) {
        for (int i = 0; i < nRow; ++i) {
            scanf("%s", map[i]);
        }

        int great_x, great_y;
        scanf("%d%d", &great_x, &great_y);
        land = map[great_x][great_y];
        if (land == 'w') water = 'l';
        else if (land == 'l') water = 'w';
        replace(great_x, great_y);

        int nLand = 0;
        for (int i = 0; i < nRow; ++i) 
            for (int k = 0; k < nCol; ++k)
                if (map[i][k] == land)
                    nLand = std::max(nLand, replace(i, k));
       
        printf("%d\n", nLand);

    }
    return 0;
}
