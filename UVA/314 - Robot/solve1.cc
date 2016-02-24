#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

const int M = 50+5;
bool track[M][M];
bool visited[M][M][4];

enum Orient { EAST = 0, SOUTH, WEST, NORTH };
const int DX[4] = {0, 1, 0, -1};
const int DY[4] = {1, 0, -1, 0};
struct Now {
    int _x, _y, _orient, _time;
    Now(int x, int y, int orient, int time = 0) : _x(x), _y(y), _orient(orient), _time(time) { }
};

Orient scanf_orient() {
    char buf[10];
    scanf("%s", buf);
    if (buf[0] == 'e') return EAST;
    else if (buf[0] == 'w') return WEST;
    else if (buf[0] == 's') return SOUTH;
    return NORTH;
}


int main() {

    int nrow, ncol;
    while (scanf("%d%d", &nrow, &ncol) == 2 and (nrow or ncol)) {
        memset(track, true, sizeof(track));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < nrow; ++i)
            for (int k = 0; k < ncol; ++k) {
                int has_block;
                scanf("%d", &has_block);
                if (has_block)
                    track[i][k] = track[i+1][k] = track[i][k+1] = track[i+1][k+1] = false;
            }
        int src_x, src_y, dst_x, dst_y;
        scanf("%d%d%d%d", &src_x, &src_y, &dst_x, &dst_y);
        Orient src_ori = scanf_orient();

        std::queue<Now> q;
        q.push(Now(src_x, src_y, src_ori)); visited[src_x][src_y][src_ori] = true;
        int cost = -1;
        while (not q.empty()) {
            Now cur = q.front(); q.pop();
            int cur_x = cur._x, cur_y = cur._y;
            int cur_ori = cur._orient;
  //          printf("%d %d %d (%d)\n", cur_x, cur_y, cur_ori, cur._time);
            if (cur_x == dst_x and cur_y == dst_y) {
                cost = cur._time;
                break;
            }

            int nx=cur_x, ny=cur_y, dx=DX[cur_ori], dy=DY[cur_ori];
            int next_time = cur._time+1;
            for (int i = 1; i <= 3; ++i) {
                nx = nx + dx;
                ny = ny + dy;
//                printf(" %d %d  %d %d\n", nx, ny, nrow, ncol);
                if (nx > 0 and nx < nrow and ny > 0 and ny < ncol) {
                    if (not track[nx][ny]) break;
                    if (not visited[nx][ny][cur_ori]) {
                        visited[nx][ny][cur_ori] = true;
                        q.push(Now(nx, ny, cur_ori, next_time));
                    }
                } else
                    break;
            }
            for (int i = 0; i < 4; ++i)
                if ((((i+4-cur_ori) % 4 == 1) or ((4+cur_ori-i) % 4 == 1)) and not visited[cur_x][cur_y][i]) {
                    visited[cur_x][cur_y][i] = true;
                    q.push(Now(cur_x, cur_y, i, next_time));
                }
        }
        printf("%d\n", cost);
    }

    return 0;
}
