#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

const int M = 50+5;
char image[M][M];
bool visited[M][M];
char buf[M];

const char BACKGROUND = '.';
const char PIXEL = 'X';

int nrow, ncol;
const int d = 4;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 0 and x < nrow and y >= 0 and y < ncol and (image[x][y] != BACKGROUND) and (not visited[x][y]);
}

void dfs(int x, int y, int & npixel);

void dfs_pixel(int x, int y, int & npixel) {
    visited[x][y] = true;
    for (int i = 0; i < d; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (valid(nx, ny) and image[nx][ny] == PIXEL) 
            dfs_pixel(nx, ny, npixel);
    }
    for (int i = 0; i < d; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (valid(nx, ny))
           dfs(nx, ny, npixel);
    }
}

void dfs(int x, int y, int & npixel) {
    assert(not visited[x][y]);
    if (image[x][y] == PIXEL) {
        ++npixel;
        dfs_pixel(x, y, npixel);
    }
    visited[x][y] = true;
    for (int i = 0; i < d; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (valid(nx, ny)) 
            dfs(nx, ny, npixel);
    }
}

int main() {
    int posCase = 1;
    while (scanf("%d%d", &ncol, &nrow) == 2 and nrow) {
        for (int i = 0; i < nrow; ++i) {
            scanf("%s", buf);
            for (int k = 0; k < ncol; ++k)
                image[i][k] = buf[k];
        }

        memset(visited, false, sizeof(visited));

        std::vector<int> vecPixel;
        for (int i = 0; i < nrow; ++i)
            for (int k = 0; k < ncol; ++k) {
                if (image[i][k] != BACKGROUND and (not visited[i][k])) {
                    int npixel = 0;
                    dfs(i, k, npixel);
                    if (npixel >= 1 and npixel <= 6)
                        vecPixel.push_back(npixel);
                }
            }

        std::sort(vecPixel.begin(), vecPixel.end());
        printf("Throw %d\n", posCase++);
        for (int i = 0; i < vecPixel.size(); ++i)
            printf("%s%d", (i == 0) ? "" : " ", vecPixel[i]);
        if (vecPixel.size() != 0)
            printf("\n");
        printf("\n");

    }
    return 0;
}
