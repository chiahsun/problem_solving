#include <cstdio>
#include <vector>
#include <algorithm>

struct UnionFind {
    std::vector<int> _parent;
    UnionFind(int size) {
        size += 1;
        _parent.resize(size);
        for (int i = 0; i < _parent.size(); ++i) _parent[i] = i;
    }

    int findRoot(int x) {
        int parent = _parent[x];
        int grand_parent = _parent[parent];
        if (parent == grand_parent) return parent;
        _parent[x] = grand_parent;
        // try _parent[rx] = x;
        while (x != _parent[x]) x = _parent[x];
        return x;
    }

    bool isUnion(int x, int y) { return findRoot(x) == findRoot(y); }

    void makeUnion(int x, int y) {
        int rx = findRoot(x);
        int ry = findRoot(y);
        _parent[rx] = ry;
    }
};

struct Edge {
    int _from, _to, _cost;
    Edge() { }
    Edge(int from, int to, int cost) : _from(from), _to(to), _cost(cost) { }
    bool operator < (const Edge & rhs) const { return _cost < rhs._cost; }
};

Edge edges[1000000+5+10];

void get_input_edge(Edge * p) {
    scanf("%d%d%d", &p->_from, &p->_to, &p->_cost);
}

void dismiss_input_edge() {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
}

int main() {
    bool first = true;
    int nNode, nAdditionalEdge, nPrevEdge;
    while (scanf("%d", &nNode) == 1 and nNode) {

        int original_cost = 0;
        for (int i = 0; i < nNode-1; ++i) {
            get_input_edge(&edges[i]);
            original_cost += edges[i]._cost;
        }
        scanf("%d", &nAdditionalEdge);
        for (int i = nNode-1; i < nNode-1+nAdditionalEdge; ++i)
            get_input_edge(&edges[i]);
        std::sort(edges, edges+nNode-1+nAdditionalEdge);
     
        int n_connect = 0;
        int new_cost = 0;
        UnionFind uf(nNode);
        for (int i = 0; i < nNode-1+nAdditionalEdge; ++i) {
            Edge & e = edges[i];
            int from = e._from, to = e._to, cost = e._cost;
            if (not uf.isUnion(from, to)) {
                uf.makeUnion(from, to);
                new_cost += cost;
                ++n_connect;
            }
            if (n_connect == nNode-1)
                break;
        }

        scanf("%d", &nPrevEdge);
        while (nPrevEdge--) dismiss_input_edge();
        if (first) first = false;
        else printf("\n");
        printf("%d\n%d\n", original_cost, new_cost);
    }
    return 0;
}
