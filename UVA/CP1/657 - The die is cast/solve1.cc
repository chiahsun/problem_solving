#include <cstdio>
#include <cstring>
#include <cassert>
#include <queue>
#include <utility>
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


void dfs_pixel(int x, int y, std::queue<std::pair<int, int> > & q) {
//    printf("  DFS pixel at (%d,%d)\n", x, y);
    if (visited[x][y])
        return;
    visited[x][y] = true;
    for (int i = 0; i < d; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (valid(nx, ny)) {
            if (image[nx][ny] == PIXEL) 
                dfs_pixel(nx, ny, q);
            else
                q.push(std::make_pair(nx, ny));
        }
    }
}

void bfs(int x, int y, int & npixel, std::queue<std::pair<int, int> > & q) {
    q.push(std::make_pair(x, y));
//    printf("Call BFS (%d,%d)\n", x, y);
    while (not q.empty()) {
        std::pair<int, int> f = q.front(); q.pop();
        int fx = f.first, fy = f.second;
  //      printf("  in BFS (%d,%d)\n", fx, fy);
        if (not visited[fx][fy]) {
            if (image[fx][fy] == PIXEL) {
                ++npixel;
    //            printf("Add pixel at (%d,%d) (%d)\n", fx, fy, npixel);
                dfs_pixel(fx, fy, q);
            } else {
                visited[fx][fy] = true;
                for (int i = 0; i < d; ++i) {
                    int nx = fx+dx[i];
                    int ny = fy+dy[i];
                    if (valid(nx, ny))
                        q.push(std::make_pair(nx, ny));
                }
            }
        }
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
                    std::queue<std::pair<int, int> > q;
                    bfs(i, k, npixel, q);
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
