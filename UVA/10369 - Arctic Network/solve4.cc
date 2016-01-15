#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

const int M = 500+5;
std::pair<int, int> nodes[M];
typedef int EdgeId;

struct UnionFind {
    int _parent[M];
    UnionFind(int nNode) {
        for (int i = 0; i < nNode; ++i)
            _parent[i] = i;
    }

    int seek(int x) {
        while (x != _parent[x]) {
            x = _parent[x];
        }
        return x; 
    }
    bool isUnion(int x, int y) {
        return seek(x) == seek(y);
    }

    int makeUnion(int x, int y) {
        int r1 = seek(x);
        int r2 = seek(y);

        if (r1 != r2) 
            _parent[r2] = r1;
       
        return r1;
    }
};

struct Edge {
    double _distance;
    int _from;
    int _to;
    Edge() { _distance = 0; _from = _to = 0; }
    Edge(int from, int to, double distance)
        : _from(from), _to(to), _distance(distance)
    {} 
    int getFrom() const { return _from; }
    int getTo() const { return _to; }
    double getDistance() const { return _distance; }
};

Edge edges[M*M/2];

struct EdgeCompare {
    bool operator () (const Edge & lhs, const Edge & rhs) const {
        return lhs.getDistance() < rhs.getDistance();
    }
};

double square(double x) { return x * x; }

int main() {
    int nCase, nSat, nNode;
    int x, y;
    
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &nSat, &nNode);

        UnionFind uf(nNode);
        for (int i = 0; i < nNode; ++i) {
            scanf("%d%d", &(nodes[i].first), &(nodes[i].second));
        }
        int posEdge = 0;
        for (int i = 0; i < nNode; ++i) {
            for (int k = i+1; k < nNode; ++k) {
                edges[posEdge++] = Edge(i, k, sqrt(square(nodes[i].first - nodes[k].first) 
                            + square(nodes[i].second - nodes[k].second)));
            }
        }
        const int nEdge = posEdge;

        std::sort(edges, edges+nEdge, EdgeCompare());
        int pos = 0;
        int cntEdge = 0;
        for (int i = 0; i < nEdge; ++i) {
            const Edge & e = edges[i];
            if (not uf.isUnion(e.getFrom(), e.getTo())) {
                uf.makeUnion(e.getFrom(), e.getTo());
                ++cntEdge;
                if (cntEdge >= (nNode-nSat)) {
                    pos = i;
                    break;
                }
            }
        }
        printf("%.2f\n", edges[pos].getDistance());

    }

    return 0;
}
