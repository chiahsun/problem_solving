#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

int get_in_node(int regulator) { return regulator << 1; }
int get_out_node(int regulator) { return regulator << 1 | 1; }

const int INF = std::numeric_limits<int>::max();
const int MAX_NUM_REGULATOR = 100+5;
const int M = MAX_NUM_REGULATOR*2+5;
const int SOURCE = 0;
const int SINK = M-1;


struct Edge {
    int _from, _to, _capacity, _flow;
    Edge(int from, int to) : _from(from), _to(to), _capacity(0), _flow(0) { }
    int get_residual_capacity() const { return _capacity - _flow; }
    int get_flow() const { return _flow; }
    void add_flow(int & update_flow) { 
        int x = std::min(update_flow, get_residual_capacity());
        update_flow -= x;
        _flow += x;
        assert(_flow >= 0 and _flow <= _capacity);
    } 
    void remove_flow(int & update_flow) {
        int x = std::min(update_flow, get_flow());
        update_flow -= x;
        _flow -= x;
        assert(_flow >= 0 and _flow <= _capacity);
    }
};

Edge* edges[M][M];
std::vector<Edge*> adjacent_edges[M];
std::vector<Edge*> adjacent_reverse_edges[M];

struct MemoryPool {
    std::vector<Edge*> _vec;
    ~MemoryPool() { for (auto p : _vec) delete p; }
    Edge* alloc(const Edge & e) { _vec.push_back(new Edge(e)); return _vec.back(); }
};

Edge* get_edge(MemoryPool & pool, int from, int to) {
    if (not edges[from][to]) {
        Edge* p_edge = pool.alloc(Edge(from, to));
        edges[from][to] = p_edge;
        adjacent_edges[from].push_back(p_edge);
        adjacent_reverse_edges[to].push_back(p_edge);
    }
    return edges[from][to];
}

int bfs_augmenting_path(std::vector<int> & path) {
    path.clear();

    bool enqueued[M];
    int prev[M], flow[M];
    memset(enqueued, false, sizeof(enqueued));
    
    std::queue<int> q;
    q.push(SOURCE); enqueued[SOURCE] = true; prev[SOURCE] = SOURCE;

    while (not q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == SINK) break;
        for (Edge* p_edge : adjacent_edges[cur]) {
            int to = p_edge->_to;
            if (not enqueued[to]) {
                if (p_edge->get_residual_capacity() > 0) {
                    q.push(to); enqueued[to] = true; prev[to] = cur; 
                    flow[to] = p_edge->get_residual_capacity();
                }
            }
        }
        for (Edge* p_reverse_edge : adjacent_reverse_edges[cur]) {
            int from = p_reverse_edge->_from;
            if (not enqueued[from]) {
                if (p_reverse_edge->get_flow() > 0) {
                    q.push(from); enqueued[from] = true; prev[from] = cur;
                    flow[from] = p_reverse_edge->get_flow();
                }
            }
        }
    }

    if (not enqueued[SINK]) return 0;
    int update_flow = 1<<30, now = SINK;
    while (prev[now] != now) {
        path.push_back(now);
        update_flow = std::min(update_flow, flow[now]);
        now = prev[now];
    }
    path.push_back(SOURCE);
    std::reverse(path.begin(), path.end());
    return update_flow;
}

void print_path(const std::vector<int> & path, int update_flow) {
    for (auto x : path)
        printf("%d -> ", x);
    printf("update flow : %d\n", update_flow);
}

int main() {

    int nRegulator, nConnection;
    while (scanf("%d", &nRegulator) == 1) {
        memset(edges, 0, sizeof(edges));
        for (int i = 0; i < M; ++i) {
            adjacent_edges[i].clear();
            adjacent_reverse_edges[i].clear();
        }
        MemoryPool pool;

        for (int i = 1; i <= nRegulator; ++i) {
            int regulator_capacity;
            scanf("%d", &regulator_capacity);
            get_edge(pool, get_in_node(i), get_out_node(i))->_capacity += regulator_capacity;
        }
        scanf("%d", &nConnection);


        for (int i = 0; i < nConnection; ++i) {
            int from_regulator, to_regulator, capacity;
            scanf("%d%d%d", &from_regulator, &to_regulator, &capacity);
            get_edge(pool, get_out_node(from_regulator), get_in_node(to_regulator))->_capacity += capacity;
        }

        int nConnectionSource, nConnectionSink;
        scanf("%d%d", &nConnectionSource, &nConnectionSink);
        for (int i = 0; i < nConnectionSource; ++i) {
            int to_regulator; 
            scanf("%d", &to_regulator);
            get_edge(pool, SOURCE, get_in_node(to_regulator))->_capacity = INF;
        }
        for (int i = 0; i < nConnectionSink; ++i) {
            int from_regulator;
            scanf("%d", &from_regulator);
            get_edge(pool, get_out_node(from_regulator), SINK)->_capacity = INF;
        }

        std::vector<int> path;
        int update_flow = 0;
        unsigned long long total_flow = 0;
        while ((update_flow = bfs_augmenting_path(path)) > 0) {
            total_flow += update_flow;
//            print_path(path, update_flow);
            for (int i = 0; i < (int)path.size()-1; ++i) {
                int from = path[i], to = path[i+1];
                int cur_flow = update_flow;
                if (get_edge(pool, from, to)) { get_edge(pool, from, to)->add_flow(cur_flow); }
                if (get_edge(pool, to, from)) { get_edge(pool, to, from)->remove_flow(cur_flow); }
            }
        }
        printf("%llu\n", total_flow);
    }
    
    return 0;
}
