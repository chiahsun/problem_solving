#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

const bool debug = false;
const int MAX_NUM_NODE = 100+5;
struct UnionFind {
    int _nNode;
    int _parent[MAX_NUM_NODE];
    // start from 1
    UnionFind(int nNode) : _nNode(nNode) { for (int i = 0; i <= nNode; ++i) _parent[i] = i; }
    int findRoot(int x) { return (x == _parent[x]) ? x : (_parent[x] = findRoot(_parent[x])); }
    bool isUnion(int x, int y) { return findRoot(x) == findRoot(y); }
    void makeUnion(int x, int y) { _parent[findRoot(x)] = findRoot(y); }
    void print() {
        for (int i = 1; i <= _nNode; ++i)
            printf("%2d", i);
        printf("\n");
        for (int i = 1; i <= _nNode; ++i)
            printf("%2d", findRoot(i));
        printf("\n");
    }
};

struct Edge {
    int _from, _to, _cost;
    Edge(int from, int to, int cost) : _from(from), _to(to), _cost(cost) { }
    bool operator < (const Edge & rhs) const { return _cost < rhs._cost; }
};
std::vector<Edge> edges;
bool visited[MAX_NUM_NODE];
std::vector<bool> edge_used;

std::vector<std::vector<int> > adjacent;

bool dfs(int cur, int dst, int & largest) {
    visited[cur] = true;

    for (int edge_id : adjacent[cur]) {
        const Edge & e = edges[edge_id];
        int from = e._from;
        int to = e._to;
        int cost = e._cost; 
        int next = (from == cur ? to : from);
        if (next == dst or (not visited[next] and dfs(next, dst, largest))) {
            largest = std::max(largest, cost);
            return true;
        }
    }
    return false;
}

int get_largest_cost_between(int from, int to) {
    memset(visited, false, sizeof(visited));
    int largest = 0;
    dfs(from, to, largest);
    return largest;
}


int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        int nNode, nEdge;
        scanf("%d%d", &nNode, &nEdge);
        edges.clear();
        adjacent.clear();
        adjacent.resize(nNode+1);
        edge_used.clear();
        edge_used.resize(nEdge, false);

        for (int i = 0; i < nEdge; ++i) {
            int from, to, cost;
            scanf("%d%d%d", &from, &to, &cost);
            edges.push_back(Edge(from, to, cost));
        }
        std::sort(edges.begin(), edges.end());


        UnionFind uf(nNode);
        int n_connect = 0;
        int total_cost = 0;
        for (int i = 0; i < nEdge; ++i) {
             int from = edges[i]._from;
             int to = edges[i]._to;
             int cost = edges[i]._cost;

             if (not uf.isUnion(from, to)) {
                 adjacent[from].push_back(i);
                 adjacent[to].push_back(i);
                 uf.makeUnion(from, to);
                 edge_used[i] = true;
                 if (debug) {
                     printf("choose %d <-> %d cost %d\n", from, to, cost);
                     uf.print();
                 }
                 total_cost += cost;
                 ++n_connect;
             } else {
                 if (debug)
                     printf("  pass %d <-> %d cost %d\n", from, to, cost);
             }
             if (n_connect >= nNode-1) 
                 break;
        }

        int second_total_cost = INT_MAX;
        for (int i = 0; i < nEdge; ++i) {
            if (not edge_used[i]) {
                int from = edges[i]._from;
                int to = edges[i]._to;
                int cost = edges[i]._cost;
                int largest_cost = get_largest_cost_between(from, to);
                if (debug)
                    printf("  replace %d <-> %d cost %d for %d (d : %d)\n", from, to, cost, largest_cost, cost - largest_cost);
                second_total_cost = std::min(total_cost+cost-largest_cost, second_total_cost);
            }
        }

        printf("%d %d\n", total_cost, second_total_cost);
    }

    return 0;
}
