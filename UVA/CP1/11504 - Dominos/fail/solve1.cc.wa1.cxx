#include <cstdio>
#include <cstring>
#include <vector>

const bool debug = false;

const int M = 100000+5;
std::vector<std::vector<int> > edges;
int parent[M];

void dfs(int cur, int src) {
    if (src != cur) {
        parent[cur] = src;
        printf("set %d with src %d\n", cur, src);
    }
    for (auto next : edges[cur]) {
        if (not parent[next] and next != src)
            dfs(next, src);
    }
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int nNode, nEdge;
        scanf("%d%d", &nNode, &nEdge);

        edges.clear();
        edges.resize(nNode+1);
        for (int posEdge = 0; posEdge < nEdge; ++posEdge) {
            int from, to;
            scanf("%d%d", &from, &to);
            edges[from].push_back(to);
        }
        memset(parent, 0, sizeof(int) * (nNode+1));
        for (int i = 1; i <= nNode; ++i) {
            if (not parent[i]) {
                dfs(i, i);
            }
        }
        int nhead = 0;
        for (int i = 1; i <= nNode; ++i)
            if (not parent[i])
                ++nhead;
        printf("%d\n", nhead);
    }
    return 0;
}
