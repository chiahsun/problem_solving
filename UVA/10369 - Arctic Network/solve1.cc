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

    std::pair<int, int> seek(int x) {
        int parent = _parent[x];
        if (x == parent)
            return std::make_pair(x, 0);

        int grand_parent = _parent[parent];
        if (parent != grand_parent)
            _parent[x] = grand_parent;
        int cnt = 1;
        while (x != _parent[x]) {
            x = _parent[x];
            ++cnt;
        }
        return std::make_pair(x, cnt);
    }
    bool isUnion(int x, int y) {
        return seek(x).first == seek(y).first;
    }

    int makeUnion(int x, int y) {
        std::pair<int, int> pr1 = seek(x);
        std::pair<int, int> pr2 = seek(y);

        if (pr1.first != pr2.first) {
            if (pr1.second <= pr2.second)
                _parent[pr2.first] = pr1.first;
            else
                _parent[pr1.first] = pr2.first;
        }
        return seek(x).first;
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
EdgeId edgeQueue[M*M/2];

struct EdgeQueueCompare {
    bool operator () (const EdgeId & lhs, const EdgeId & rhs) const {
        return edges[lhs].getDistance() < edges[rhs].getDistance();
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
                edgeQueue[posEdge] = posEdge;
                edges[posEdge++] = Edge(i, k, sqrt(square(nodes[i].first - nodes[k].first) 
                            + square(nodes[i].second - nodes[k].second)));
            }
        }
        const int nEdge = posEdge;
#if 0
        for (int i = 0; i < nEdge; ++i) {
            const Edge & e = edges[i];
            printf("%d -> %d (%f)\n", e.getFrom(), e.getTo(), e.getDistance());
        }
        printf("\n");
        for (int i = 0; i < nEdge; ++i) {
            const Edge & e = edges[edgeQueue[i]];
            printf("(%d) %d -> %d (%f)\n", edgeQueue[i], e.getFrom(), e.getTo(), e.getDistance());
        }
        printf("\n");
#endif

        std::sort(edgeQueue, edgeQueue+nEdge, EdgeQueueCompare());
#if 0
        for (int i = 0; i < nEdge; ++i) {
            const Edge & e = edges[edgeQueue[i]];
            printf("%d -> %d (%f)\n", e.getFrom(), e.getTo(), e.getDistance());
        }
#endif
        int pos = 0;
        int cntEdge = 0;
        for (int i = 0; i < nEdge; ++i) {
            const Edge & e = edges[edgeQueue[i]];
            if (not uf.isUnion(e.getFrom(), e.getTo())) {
                uf.makeUnion(e.getFrom(), e.getTo());
                //                    printf("select %d -> %d (%f)\n", e.getFrom(), e.getTo(), e.getDistance());
                ++cntEdge;
                if (cntEdge >= (nNode-nSat)) {
                    pos = i;
                    break;
                }
            }
        }
        printf("%.2f\n", edges[edgeQueue[pos]].getDistance());

    }

    return 0;
}
