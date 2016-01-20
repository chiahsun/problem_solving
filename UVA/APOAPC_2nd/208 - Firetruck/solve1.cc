#include <cstdio>
#include <cstring>
#include <algorithm>

const int M = 21 + 5;

struct UnionFind {
    int _parent[M];
    UnionFind() { for (int i = 0; i < M; ++i) _parent[i] = i; }
    int seek(const int x) {
        int p = _parent[x];
        if (p == x) return x;
        
        while (p != _parent[p]) 
            p = _parent[p];
        
        return (_parent[x] = p);
    }

    bool isUnion(int x, int y) { return seek(x) == seek(y); }
    int makeUnion(int x, int y) { 
        int rx = seek(x);
        int ry = seek(y);
        return (_parent[ry] = rx);
    }
};


int edges[M][2 * M];
int nEdge[M];
bool visited[M];
int route[M];

void dfs(int cur, int depth, int & cntRoute, UnionFind & uf, const int & dest) {
    route[depth] = cur;
    if (cur == dest) {
        for (int i = 0; i <= depth; ++i)
            printf("%s%d", (i == 0 ? "" : " "), route[i]);
        printf("\n");
        ++cntRoute;
        return;
    }

    for (int i = 0; i < nEdge[cur]; ++i) {
        int next = edges[cur][i];
        if (uf.isUnion(next, dest) and not visited[next]) {
            visited[next] = true;
            dfs(next, depth+1, cntRoute, uf, dest);
            visited[next] = false;
        }
    }
}

int main() {
    int dest;
    int posCase = 1;
    while (scanf("%d", &dest) == 1 and dest) {
        UnionFind uf;
        memset(nEdge, 0, sizeof(nEdge));

        int a, b;
        while (scanf("%d%d", &a, &b) == 2 and a) {
            uf.makeUnion(a, b);

            edges[a][nEdge[a]] = b;
            ++nEdge[a];
            edges[b][nEdge[b]] = a;
            ++nEdge[b];
        }

        for (int i = 1; i < M; ++i) {
            std::sort(edges[i], edges[i]+nEdge[i]);
            auto it = std::unique(edges[i], edges[i]+nEdge[i]);
            nEdge[i] = it - edges[i] ;
            std::sort(edges[i], edges[i]+nEdge[i]);
        }
        printf("CASE %d:\n", posCase++);
        int depth = 0, cntRoute = 0;
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        dfs(1, depth, cntRoute, uf, dest);
        printf("There are %d routes from the firestation to streetcorner %d.\n", cntRoute, dest);
    }

    return 0;
}
