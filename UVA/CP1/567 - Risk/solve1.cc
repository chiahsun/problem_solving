#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
bool visited[20+1];
char buf[50];

int main() {
    int posCase = 1;
    while (true) {
        std::vector<std::vector<int> > edges;
        edges.resize(21);
        for (int i = 1; i <= 19; ++i) {
            int nadj, adj;
            bool ok = (scanf("%d", &nadj) == 1);
            if (not ok) return 0;
            while (nadj--) {
                scanf("%d", &adj);
                edges[i].push_back(adj);
                edges[adj].push_back(i);
//                printf("add %d -> %d\n", i, adj);
            }
        }
        int nquery, src, dst;
        scanf("%d", &nquery);
        printf("Test Set #%d\n", posCase++);
        while (nquery--) {
            scanf("%d%d", &src, &dst);
            std::queue<int> q[2];
            q[0].push(src);
            memset(visited, false, sizeof(visited));
            visited[src] = true;
            bool found = false;
            int cost = 0;
            while (not q[0].empty() or not q[1].empty()) {
                std::queue<int> & qcur = q[0].empty() ? q[1] : q[0];
                std::queue<int> & qnext = q[0].empty() ? q[0] : q[1];
                while (not qcur.empty()) {
                    int f = qcur.front(); qcur.pop();

                    if (f == dst) { found = true; break; }
                    for (const auto & adj : edges[f]) {
                        if (not visited[adj]) {
                            visited[adj] = true;
                            qnext.push(adj);
                        }
                    }
                }
                if (found) break;
                ++cost;
            }
            printf("%2d to %2d:%2d\n", src, dst, cost);
        }

        printf("\n");
    }
    return 0;
}
