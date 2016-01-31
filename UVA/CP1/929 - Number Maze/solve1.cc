#include <cstdio>
#include <queue>
const int M = 1000+5;
int maze[M][M];
int distance[M][M];

int NOT_VISITED = -1;

struct Now {
    int _x, _y, _distance;
    Now(int x, int y, int distance) : _x(x), _y(y), _distance(distance) { }
    int x() const { return _x; }
    int y() const { return _y; }
    int distance() const { return _distance; }
    bool operator < (const Now & rhs) const { return _distance > rhs._distance; }
};

int main() {
    int nMaze, nRow, nCol;
    scanf("%d", &nMaze);
    while (nMaze--) {
        scanf("%d%d", &nRow, &nCol);
        for (int i = 0; i < nRow; ++i)
            for (int k = 0; k < nCol; ++k) {
                scanf("%d", &maze[i][k]);
                distance[i][k] = -1;
            }

        distance[0][0] = maze[0][0];
        std::priority_queue<Now> pq;
        pq.push(Now(0, 0, maze[0][0]));

        while (not pq.empty()) {
            Now t = pq.top(); pq.pop();
            int cur_x = t.x();
            int cur_y = t.y();
            int cur_distance = t.distance();
            int dst_distance = distance[nRow-1][nCol-1];
            if (dst_distance != NOT_VISITED and cur_distance > dst_distance) break;

            static const int SZ = 4;
            static const int dx[SZ] = {1, -1, 0, 0};
            static const int dy[SZ] = {0, 0, 1, -1};
            for (int i = 0; i < SZ; ++i) {
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if (nx >= 0 and nx < nRow and ny >= 0 and ny < nCol) {
                    int old_distance = distance[nx][ny];
                    int new_distance = cur_distance + maze[nx][ny];
                    if (old_distance == NOT_VISITED or new_distance < old_distance) {
                        distance[nx][ny] = new_distance;
                        pq.push(Now(nx, ny, new_distance));
                    }
                }
            }
        }

        printf("%d\n", distance[nRow-1][nCol-1]);
    }
    return 0;
}
