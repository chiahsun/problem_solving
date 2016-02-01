#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

const int M = 750+5;

struct UnionFind {
    int _parent[M];
    UnionFind(int nNode) { for (int i = 0; i < nNode; ++i) _parent[i] = i; }

    int findRoot(int x) { return (x == _parent[x] ? x : (_parent[x] = findRoot(_parent[x]))); }

    bool isUnion(int x, int y) { return findRoot(x) == findRoot(y); }

    void makeUnion(int x, int y) { _parent[findRoot(x)] = findRoot(y); }
};

struct Node {
    int _x, _y;
} nodes[M];

struct Edge {
    int _from, _to;
    double _distance;
    Edge(int from, int to, double distance) 
      : _from(from), _to(to), _distance(distance) { }
    bool operator < (const Edge & rhs) const { return _distance < rhs._distance; }
};

double square(int d) { return d * d; }

double get_distance(int x, int y) {
    return sqrt(square(nodes[x]._x - nodes[y]._x) + square(nodes[x]._y - nodes[y]._y));
}

int main() {
    int nNode, nExistedEdge;
    while (scanf("%d", &nNode) == 1 and nNode) {
        for (int i = 0; i < nNode; ++i)
            scanf("%d%d", &nodes[i]._x, &nodes[i]._y);


        UnionFind uf(nNode);
        int n_connect = 0;
        scanf("%d", &nExistedEdge);
        while (nExistedEdge--) {
            int from, to;
            scanf("%d%d", &from, &to);
            --from, --to;
            if (not uf.isUnion(from, to)) {
                uf.makeUnion(from, to);
                ++n_connect;
            }
        }

        std::vector<Edge> vecEdge;
        if (n_connect < nNode-1) {
            for (int i = 0; i < nNode; ++i)
                for (int k = i+1; k < nNode; ++k) {
                    if (not uf.isUnion(i, k))
                        vecEdge.push_back(Edge(i, k, get_distance(i, k)));
                }
        }

        std::sort(vecEdge.begin(), vecEdge.end());

        double total_distance = 0;
        for (const auto & e : vecEdge) {
            int from = e._from;
            int to = e._to;
            double distance = e._distance;
            if (not uf.isUnion(from, to)) {
                total_distance += distance;
                uf.makeUnion(from, to);
                ++n_connect;
            }
            if (n_connect >= nNode-1)
                break;
        }
        printf("%.2lf\n", total_distance);

    }
    return 0;
}
