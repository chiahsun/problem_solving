#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
int N, other, nDepend;

const int M = 100+5;

int nedge[M];
int edge[M][M];
bool visited[M];

void dfs(int x, int & cnt) {
    if (not visited[x]) {
        visited[x] = true;
        ++cnt;
        for (int i = 0; i < nedge[x]; ++i) {
            int prev = edge[x][i];
            dfs(prev, cnt);
        }
    }
}

int main() {
    while (scanf("%d", &N) == 1 and N) {
        memset(nedge, 0, sizeof(nedge));
        memset(edge, 0, sizeof(edge));
        for (int pos = 1; pos <= N; ++pos) {
            scanf("%d", &nDepend);
            while (nDepend--) {
                scanf("%d", &other);
                edge[pos][nedge[pos]++] = other;
            }
        }

        int vmax = 0, pmax = 1;
        for (int i = 1; i <= N; ++i) {
            int cnt = 0;
            memset(visited, false, sizeof(visited));
            dfs(i, cnt);
            if (cnt > vmax) {
                vmax = cnt;
                pmax = i;
            }
        }

        // printf("%d with cnt %d\n", vecRoots[0], src_cnt[vecRoots[0]]);
        printf("%d\n", pmax);
    }
    return 0;
}
