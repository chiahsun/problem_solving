#include <cstdio>
#include <cstring>
#include <utility>
#include <map>
#include <algorithm>

// const bool debug = false;
const bool debug = true;

const int M = 20 + 5;
int maze[M][M];
int cost[M][M];
std::map<int, int> bcost[M][M];

const int INIT = M * M;

int nRow, nCol, nThrough;
            
const int dx[4] = {1, -1, 0,  0};
const int dy[4] = {0,  0, 1, -1};

void print_cost() {
    for (int i = 0; i < nRow; ++i) {
        for (int k = 0; k < nCol; ++k)
            printf("%d ", cost[i][k]);
        printf("\n");
    }
        printf("\n");
}

bool is_in_maze(int x, int y) {
    return (x >= 0) and (x < nRow) and (y >= 0) and (y < nCol);
}

bool is_valid(int x, int y) {
    return is_in_maze(x, y) and (maze[x][y] == 0);
}

// use bfs for block search
void dfs(int x, int y, int cur_cost, int cur_through) {
    cur_cost += 1;
    cur_through = (maze[x][y] == 0) ? nThrough : (cur_through-1);
    if (cur_through < 0)
        return;
    if (maze[x][y] == 0) {
        if (cost[x][y] <= cur_cost)
            return;
        cost[x][y] = cur_cost;
//        print_cost();
    } else {
        if (bcost[x][y].count(cur_through) == 0) {
            bcost[x][y].insert(std::make_pair(cur_through, cur_cost));
        } else {
            int prev_cost = bcost[x][y][cur_through];
            if (prev_cost <= cur_cost)
                return;
            else
                bcost[x][y][cur_through] = cur_cost;
        }
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_in_maze(nx, ny))
            dfs(nx, ny, cur_cost, cur_through);
    }
}

int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%d%d%d", &nRow, &nCol, &nThrough);

        for (int i = 0; i < nRow; ++i)
            for (int k = 0; k < nCol; ++k) 
                scanf("%d", &maze[i][k]);
#if 0 
        for (int i = 0; i < nRow; ++i) {
            for (int k = 0; k < nCol; ++k) 
                printf("%d ", maze[i][k]);
            printf("\n");
        }
#endif
        for (int i = 0; i < M; ++i)
            for (int k = 0; k < M; ++k) {
                cost[i][k] = INIT;
                bcost[i][k].clear();
            }
        dfs(0, 0, 0, nThrough);
        int cst = cost[nRow-1][nCol-1];

        if (bcost[nRow-1][nCol-1].size() != 0) {
            for (const auto & pr : bcost[nRow-1][nCol-1]) {
                cst = std::min(cst, pr.second);
            }
        }

        printf("%d\n", ((cst == INIT) ? -1 : (cst-1)));
    }

    return 0;
}
