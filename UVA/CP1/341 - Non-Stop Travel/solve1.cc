#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

const bool debug = false;
const int M = 10+5;

struct Edge {
    int _from, _to, _cost;
    Edge() { }
    Edge(int from, int to, int cost) : _from(from), _to(to), _cost(cost) { }
};
std::vector<Edge> adjacent[M];
const int NOT_REACHABLE = -1;
int distance[M];
int prev[M];


struct Now {
    int _position, _cost;
    Now(int position, int cost) : _position(position), _cost(cost) { }
    int position() const { return _position; }
    int cost() const { return _cost; }
    bool operator < (const Now & rhs) const { return _cost > rhs._cost; }
};

void print_path(int src, int now) {
    if (src != now) {
        print_path(src, prev[now]);
    }
    printf(" %d", now);
}

void print_pq (std::priority_queue<Now> & pq) {
    std::vector<Now> v;
    while (not pq.empty()) {
        v.push_back(pq.top()); pq.pop();
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        printf(" %d(%d)", it->position(), it->cost());
        pq.push(*it);
    }
    printf(" size : %lu\n", v.size());
}

int main() {
    int nNode, nEdge, posCase = 1;
    while (scanf("%d", &nNode) == 1 and nNode) {
        for (int from = 1; from <= nNode; ++from) {
            adjacent[from].clear();
            scanf("%d", &nEdge);
            int to, cost;
            while (nEdge--) {
                scanf("%d%d", &to, &cost);
                adjacent[from].push_back(Edge(from, to, cost));
                if (debug)
                    printf("add %d -> %d (%d)\n", from, to, cost);
            }
            distance[from] = NOT_REACHABLE;
        }
        
        int src, dst;
        scanf("%d%d", &src, &dst);
        distance[src] = 0;
        prev[src] = src;
        std::priority_queue<Now> pq;
        pq.push(Now(src, 0));
        while (not pq.empty()) {
            if (debug) {
                printf("pq : ");
                print_pq(pq);
            };
            Now t = pq.top(); pq.pop();
            int cur = t.position();
            int cur_cost = t.cost();
            if (debug)
                printf("cur %d with cost %d\n", cur, cur_cost);
            if (distance[dst] != NOT_REACHABLE and t.cost() > distance[dst]) break;
            for (const auto & e : adjacent[cur]) {
                int next = e._to;
                int new_distance = cur_cost + e._cost;
                if (distance[next] == NOT_REACHABLE or (distance[next] > new_distance)) {
                    prev[next] = cur; 
                    distance[next] = new_distance;
                    Now next_now(next, new_distance);
                    pq.push(next_now);
                    if (debug)
                        printf("    add %d with new cost %d \n", next_now.position(), next_now.cost());
                }
            }
        }

        printf("Case %d: Path =", posCase++);
        print_path(src, dst);
        printf("; %d second delay\n", distance[dst]);
    }
    return 0;
}
