#include <cstdio>
#include <cstring>
#include <queue>

const int M = 30+5;
char maze[M][M][M];
bool visited[40000];

const char BLOCK = '#';
const char SOURCE = 'S';
const char EXIT = 'E';

int hashCode(int x, int y, int z) {
    return M*((M*x)+y)+z;
}

int source, exit;
struct Now { int _x, _y, _z; 
    Now() { }
    Now(int x, int y, int z) : _x(x), _y(y), _z(z) { } 
};
int main() {
    int nheight, nrow, ncol;
    while (scanf("%d%d%d", &nheight, &nrow, &ncol) == 3) {
        if (nheight == 0 and nrow == 0 and ncol == 0)
            break;
        Now source_now;
        for (int i = 0; i < nheight; ++i)
            for (int k = 0; k < nrow; ++k) {
                scanf("%s", maze[i][k]);
                for (int m = 0; m < ncol; ++m) {
                    if (maze[i][k][m] == SOURCE) {
                        source_now = Now(i, k, m);
                        source = hashCode(i, k, m);
                    }
                    else if (maze[i][k][m] == EXIT) exit = hashCode(i, k, m);
                }
            }
        std::queue<Now> q[2];
        q[0].push(source_now);
        memset(visited, false, sizeof(visited));
        visited[source] = true;
        int exit_cost = -1;
        int cost = 0;
        while (not q[0].empty() or not q[1].empty()) {
            std::queue<Now> & qcur = q[0].empty() ? q[1] : q[0];
            std::queue<Now> & qnext = q[0].empty() ? q[0] : q[1];
            while (not qcur.empty()) {
                Now now = qcur.front(); qcur.pop();
                if (hashCode(now._x, now._y, now._z) == exit) {
                    exit_cost = cost;
                    break;
                }
                const int SZ = 6;
                int dx[SZ] = {1, -1, 0, 0, 0, 0};
                int dy[SZ] = {0, 0, 1, -1, 0, 0};
                int dz[SZ] = {0, 0, 0, 0, 1, -1};
                for (int i = 0; i < SZ; ++i) {
                    int nx = now._x+dx[i];
                    int ny = now._y+dy[i];
                    int nz = now._z+dz[i];
                    int index = hashCode(nx, ny, nz);
                    if (nx >= 0 and nx < nheight and ny  >= 0 and ny < nrow and nz >= 0 and nz < ncol and (not visited[index]) and maze[nx][ny][nz] != BLOCK) {
                        qnext.push(Now(nx, ny, nz));
                        visited[index] = true;
                    }
                }
            }
            if (exit_cost > 0)
                break;
            ++cost;
        }
        if (exit_cost == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", exit_cost);
    }
    return 0;
}
