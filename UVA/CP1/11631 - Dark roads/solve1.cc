#include <cstdio>
#include <vector>
#include <algorithm>

struct UnionFind {
    std::vector<int> _parent;
    UnionFind(int size) { 
        _parent.resize(size); 
        for (int i = 0; i < _parent.size(); ++i) _parent[i] = i;
    }

    int findRoot(int x) {
        int parent = _parent[x];
        int grand_parent = _parent[parent];
        if (grand_parent == parent) 
            return parent;

        _parent[x] = grand_parent;
        while (x != _parent[x]) { x = _parent[x]; }
        return x;
    }

    bool isUnion(int x, int y) { 
        return (findRoot(x) == findRoot(y));
    }

    void makeUnion(int x, int y) {
        int rx = findRoot(x);
        int ry = findRoot(y);
        if (rx != ry)
            _parent[ry] = rx;
    }
};

struct Edge {
    int _from, _to, _cost;
    Edge() {}
    Edge(int from, int to, int cost) : _from(from), _to(to), _cost(cost) { }
    bool operator < (const Edge & rhs) const { return _cost < rhs._cost; }
} edges[200000+5];

int main() {
    int nNode, nEdge;
    while (scanf("%d%d", &nNode, &nEdge) == 2 and nNode) {
        int original_cost = 0;
        for (int posEdge = 0; posEdge < nEdge; ++posEdge) {
            int from, to, cost;
            scanf("%d%d%d", &from, &to, &cost);
            edges[posEdge] = Edge(from, to, cost);
            original_cost += cost;
        }

        std::sort(edges, edges+nEdge);

        UnionFind uf(nNode);
        int n_connect = 0;
        int total_cost = 0;
        for (int i = 0; i < nEdge; ++i) {
            Edge & e = edges[i];
            if (not uf.isUnion(e._from, e._to)) {
                ++n_connect;
                total_cost += e._cost;
                uf.makeUnion(e._from, e._to);
            }
            if (n_connect == nNode-1)
                break;
        }

        printf("%d\n", original_cost-total_cost);
    }
    return 0;
}
