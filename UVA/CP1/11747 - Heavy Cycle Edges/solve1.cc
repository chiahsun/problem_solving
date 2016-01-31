#include <cstdio>
#include <vector>
#include <algorithm>

// Reference
//   http://www.csie.ntnu.edu.tw/~u91029/SpanningTree.html
struct UnionFind {
    std::vector<int> _parent;
    UnionFind(int size) {
        _parent.resize(size);
        for (int i = 0; i < _parent.size(); ++i) _parent[i] = i;
    }
    int findRoot(int x) { return (_parent[x] == x) ? x : (x = findRoot(_parent[x])); }

    void makeUnion(int x, int y) { _parent[findRoot(x)] = findRoot(y); }

    bool isUnion(int x, int y) { return findRoot(x) == findRoot(y); } 
};

struct Edge {
    int _from, _to, _cost;
    bool operator < (const Edge & rhs) const { return _cost < rhs._cost; }
} edges[25000+5];

void get_input_edge(Edge * e) {
    scanf("%d%d%d", &e->_from, &e->_to, &e->_cost);
}

int main() {
    int nNode, nEdge;
    while (scanf("%d%d", &nNode, &nEdge) == 2 and nNode) {
        for (int posEdge = 0; posEdge < nEdge; ++posEdge)
            get_input_edge(&edges[posEdge]);
        std::sort(edges, edges+nEdge);

        UnionFind uf(nNode);
        int n_heaviest = 0, n_connect = 0;
        for (int i = 0; i < nEdge; ++i) {
            Edge & e = edges[i];
            int from = e._from, to = e._to, cost = e._cost;
            if (n_connect >= nNode-1 or uf.isUnion(from, to)) {
                printf("%s%d", n_heaviest == 0 ? "" : " ", cost);
                ++n_heaviest;
            } else {
                uf.makeUnion(from, to);
                ++n_connect;
            }
        }
        printf("%s\n", n_heaviest == 0 ? "forest" : "");
    }
    return 0;
}
