#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

struct Edge {
    int _from, _to, _capcity, _flow;
    Edge(int from, int to) : _from(from), _to(to), _capcity(0), _flow(0) { }
    int get_another(int cur) { return cur == _from ? _to : _from; }
    int get_capacity() const { return _capcity; }
    int get_flow(int from) const { return from == _from ? _flow : -_flow; }
    int get_residual_capacity(int from) const { 
        return get_capacity() - get_flow(from); 
    }
    void update_flow(int from, int flow) {
        if (from == _from) _flow += flow;
        else _flow -= flow;
    }
};

template <class T>
struct MemoryPool {
    std::vector<T*> _vecPointer;
    ~MemoryPool() { for (auto p : _vecPointer) delete p; }
    T* alloc(Edge e) { _vecPointer.push_back(new Edge(e)); return _vecPointer.back(); } 
};

const int M = 100+5;
Edge* edges[M][M];
std::vector<Edge*> adjacent_edges[M];

int bfs(int source, int sink, std::vector<int> & path) {
    bool enqueued[M];
    int prev[M];
    int flow[M];
    memset(enqueued, false, sizeof(enqueued));
    memset(flow, 0, sizeof(flow));
    std::queue<int> q;
    q.push(source); enqueued[source] = true; prev[source] = source;
    while (not q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == sink) break;
        for (auto p_edge : adjacent_edges[cur]) {
            int next = p_edge->get_another(cur);
            if (not enqueued[next] and p_edge->get_residual_capacity(cur) > 0) {
                flow[next] = p_edge->get_residual_capacity(cur);
                q.push(next); enqueued[next] = true; prev[next] = cur;
            }
        }
    }
    if (not enqueued[sink]) return 0;

    int update_flow = 1 << 30;
    int now = sink;
    path.clear();
    while (prev[now] != now) {
        path.push_back(now);
        update_flow = std::min(update_flow, flow[now]);
        now = prev[now];
    }
    path.push_back(source);
    std::reverse(path.begin(), path.end());
    return update_flow;
}

int main() {
    int nNode, source, sink, nEdge, posNetwork = 1;
    while (scanf("%d", &nNode) == 1 and nNode) {
        scanf("%d%d%d", &source, &sink, &nEdge);

        MemoryPool<Edge> edge_pool;
        for (int i = 0; i < M; ++i) adjacent_edges[i].clear();
        memset(edges, 0, sizeof(edges));

        for (int i = 0; i < nEdge; ++i) {
            int from, to, capacity;
            scanf("%d%d%d", &from, &to, &capacity);
            if (not edges[from][to]) {
               Edge* p_edge = edges[from][to] = edges[to][from] = edge_pool.alloc(Edge(from, to));
               adjacent_edges[from].push_back(p_edge);
               adjacent_edges[to].push_back(p_edge);
            }
            edges[from][to]->_capcity += capacity;
        }

        std::vector<int> path;
        int update_flow, total_flow = 0;
        while ((update_flow = bfs(source, sink, path))) {
            total_flow += update_flow;
            for (int i = 0; i < (int)path.size()-1; ++i) {
                int cur = path[i], next = path[i+1];
           //     printf(" update %d -> %d with flow %d\n", cur, next, update_flow);
                edges[cur][next]->update_flow(cur, update_flow);
            }
        }  
        printf("Network %d\nThe bandwidth is %d.\n\n", posNetwork++, total_flow);
    }
    return 0;
}
