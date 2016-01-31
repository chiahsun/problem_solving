#include <cstdio>
#include <cmath>
#include <algorithm>

const int M = 100+5;
struct UnionFind {
    int _parent[M];
    UnionFind() { for (int i = 0; i < M; ++i) _parent[i] = i; }
    void makeUnion(int x, int y) {
        int rx = findRoot(x);
        int ry = findRoot(y);
        _parent[rx] = ry;
    }
    int findRoot(int x) {
        int parent = _parent[x];
        int grand_parent = _parent[parent];
        if (grand_parent == parent)
            return parent;
        _parent[x] = grand_parent;
        while (_parent[x] != x) {
            x = _parent[x];
        }
        return x;
    }
    bool isUnion(int x, int y) { return findRoot(x) == findRoot(y); } 
};

struct Edge {
    int _from, _to;
    double _distance;
    Edge() {}
    Edge(int from, int to, double distance) : _from(from), _to(to), _distance(distance) { }
    bool operator < (const Edge & rhs) const
      { return _distance < rhs._distance; }
};

struct Node { double _x, _y; };

Node nodes[M];
Edge edges[M*(M-1)/2+5];

double square(double x) { return x * x; }

double get_distance(int i, int k) {
    return sqrt(square(nodes[i]._x - nodes[k]._x) + square(nodes[i]._y - nodes[k]._y));
}


int main() {
    bool first = true;
    int nCase, nNode;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &nNode);
        for (int posNode = 0; posNode < nNode; ++posNode)
            scanf("%lf%lf", &nodes[posNode]._x, &nodes[posNode]._y);
        int posEdge = 0;
        for (int i = 0; i < nNode-1; ++i)
            for (int k = i+1; k < nNode; ++k) {
                edges[posEdge++] = Edge(i, k, get_distance(i, k));
            }
        std::sort(edges, edges+posEdge);

        UnionFind uf;
        int n_connect = 0;
        double total_distance = 0;
        for (int i = 0; i < posEdge;++i) {
            int from = edges[i]._from;
            int to  = edges[i]._to;
            if (not uf.isUnion(from, to)) {
                uf.makeUnion(from, to);
                ++n_connect;
                total_distance += edges[i]._distance;
            }
            if (n_connect == nNode-1)
                break;
        }
        if (first) first = false;
        else printf("\n");
        printf("%.2lf\n", total_distance);
    }
    
    return 0;
}
