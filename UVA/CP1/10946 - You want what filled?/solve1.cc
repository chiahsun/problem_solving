#include <cstdio>
#include <vector>
#include <algorithm>

const int M = 50+5;
const char LAND = '.';

int nrow, ncol;
char map[M][M];

void dfs(int x, int y, char c, int & cnt) {
    ++cnt;
    map[x][y] = LAND;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 and nx < nrow and ny >= 0 and ny < ncol and map[nx][ny] == c)
            dfs(nx, ny, c, cnt);
    }
}

struct Hole { 
    char _c; int _cnt; 
    Hole(char c, int cnt) : _c(c), _cnt(cnt) { } 
    bool operator < (const Hole & rhs) const {
        if (_cnt != rhs._cnt) return _cnt > rhs._cnt;
        return _c < rhs._c;
    }
};

int main() {
    int posCase = 1;
    while (scanf("%d%d", &nrow, &ncol) == 2 and nrow) {
        for (int i = 0; i < nrow; ++i)
            scanf("%s", map[i]);
        std::vector<Hole> vecHole;
        for (int i = 0; i < nrow; ++i)
            for (int k = 0; k < ncol; ++k) {
                char cur = map[i][k];
                int cnt = 0;
                if (cur != LAND) {
                    dfs(i, k, cur, cnt);
                    vecHole.push_back(Hole(cur, cnt));
                }
            }

        std::sort(vecHole.begin(), vecHole.end());

        printf("Problem %d:\n", posCase++);
        for (const auto & hole : vecHole) {
            printf("%c %d\n", hole._c, hole._cnt);
        }
    }
    return 0;
}
