#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

struct Edge {
    int _from, _to, _capacity;
    int _flow;
    Edge(int one, int other, int capacity)
      : _from(one), _to(other), _capacity(capacity), _flow(0) { }
    int get_other(int one) const { return (one == _from) ? _to: _from; }
    int get_capacity() const { return _capacity; }
    int get_flow(int from) const {
        assert(abs(_flow) <= get_capacity());
        if (from == _from) return _flow;
        return -_flow;
    }
    int update_flow(int from, int flow) {
        if (from == _from) _flow += flow;
        else _flow -= flow;
        return get_flow(from);
    }
};

const int M = 100+5;
std::vector<int> adjacent_nodes[M];
Edge* edges[M][M];
bool visited[M];

int dfs_has_augmenting_path(int cur, int sink, std::vector<int> & path) {
    if (visited[cur]) return 0;
    visited[cur] = true;
    if (cur == sink) { path.push_back(sink); return 1<<30; }
    for (auto to : adjacent_nodes[cur]) {
        Edge* p_edge = edges[cur][to];
        if (p_edge->get_capacity() - p_edge->get_flow(cur) > 0) {
            int next_flow = std::min(p_edge->get_capacity() - p_edge->get_flow(cur) 
                                   , dfs_has_augmenting_path(to, sink, path));
            if (next_flow > 0) {
                path.push_back(cur);
                return next_flow;
            }
        }
    }
//    visited[cur] = false;
    return 0;
}

int has_augmenting_path(int from, int sink, std::vector<int> & path) {
    path.clear();
    memset(visited, false, sizeof(visited));
    int update_flow = dfs_has_augmenting_path(from, sink, path);
    std::reverse(path.begin(), path.end());
    return update_flow;
}

void print_path(const std::vector<int> & path) {
    for (auto x : path)
        printf("%d -> ", x);
}

void update_augmenting_path(std::vector<int> & path, int update_flow) {
    for (int i = 0; i < path.size()-1; ++i) {
        int from = path[i], to = path[i+1];
        edges[from][to]->update_flow(from, update_flow);
    }
}

int main() {
    int nNode, source, sink, nEdge, posNetWork = 1;
    while (scanf("%d", &nNode) == 1 and nNode) {
        std::vector<Edge*> edge_pool;
        scanf("%d%d%d", &source, &sink, &nEdge);
        memset(edges, 0, sizeof(edges));
        for (int i = 0; i < M; ++i)
            adjacent_nodes[i].clear();
        for (int i = 0; i < nEdge; ++i) {
            int one, other, capacity;
            scanf("%d%d%d", &one, &other, &capacity);
            if (edges[one][other]) {
                edges[one][other]->_capacity += capacity;
            } else {
                Edge* p_edge = new Edge(one, other, capacity);
                edge_pool.push_back(p_edge);
                adjacent_nodes[one].push_back(other);
                adjacent_nodes[other].push_back(one);
                edges[one][other] = edges[other][one] = p_edge;
            }
        }


        std::vector<int> path;
        int update_flow, total_flow = 0;
        while((update_flow = has_augmenting_path(source, sink, path)) != 0) { 
//            print_path(path);
//            printf(" with update flow : %d\n", update_flow);
            update_augmenting_path(path, update_flow);
            total_flow += update_flow;
        }

        printf("Network %d\nThe bandwidth is %d.\n\n", posNetWork++, total_flow);

        for (Edge* p_edge : edge_pool) 
            delete p_edge;
    }
    return 0;
}

