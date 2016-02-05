#include <cstdio>
#include <cstring>
#include <cassert>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>

const bool debug = false;

struct Edge {
    int _from, _to, _cost;
    Edge() {}
    Edge(int from, int to, int cost) : _from(from), _to(to), _cost(cost) { }
    int from() const { return _from; }
    int to() const { return _to; }
    int cost() const { return _cost; }
};

int nNode, nEdge;
std::vector<Edge> edges;
std::vector<std::vector<int> > adjacent;

const int M = 1000+5;
const int NOT_DEFINED = -1;
int prev[M]; // store edge id 
int distance[M];

struct Now {
    int _position, _distance;
    Now(int position, int distance) : _position(position), _distance(distance) { }
    int position() const { return _position; }
    int distance() const { return _distance; }
    bool operator < (const Now & rhs) const { return _distance > rhs._distance; }
};

bool detect_negative_cycle(int edge_id, int end_position) {
     if (debug)
         printf("  %d ", end_position);

     int total_cost = 0;
     int cntNode = nNode;
     while (edge_id != NOT_DEFINED and cntNode--) {
         int from = edges[edge_id].from();
         int cost = edges[edge_id].cost();
         total_cost += cost;
         if (debug)
             printf(" <---(%d)--- %d", cost, from);
         if (from == end_position) { 
             if (debug)
                 printf(" (cycle with total_cost : %d)\n", total_cost);
             return total_cost < 0;
         }
         edge_id = prev[from];
     }
     if (debug)
         printf("%s\n", cntNode == -1 ? " (until bound)" : " (not cycle)");
     return false; 
}

bool hasNegativeCycle(int start_node) {
    for (int i = 0; i < nNode; ++i) {
        prev[i] = NOT_DEFINED;
        distance[i] = INT_MAX;
    }
    if (debug)
        printf("start from %d\n", start_node);
    std::priority_queue<Now> pq;
    pq.push(Now(start_node, 0));

    int cnt = nNode + nEdge;
    while (not pq.empty() and cnt--) {
        Now t = pq.top(); pq.pop();

        int cur_position = t.position();
        int cur_distance = t.distance();
        if (debug)
            printf("  cur : %d with distance %d\n", cur_position, cur_distance);

        for (int edge_id : adjacent[cur_position]) {
            const auto & e = edges[edge_id];
            int next_position = e.to();
            int next_cost = e.cost();
            int next_distance = cur_distance + next_cost;
            if (distance[next_position] > next_distance) {
                prev[next_position] = edge_id;
                if (debug)
                    printf("    set %d with prev %d\n", next_position, cur_position);
                distance[next_position] = next_distance;
                pq.push(Now(next_position, next_distance));
#if 0
                if (detect_negative_cycle(prev[next_position], next_position))
                    return true;
#endif
            }
        }
    }
    if (debug)
        printf("cnt : %d\n", cnt);

    return cnt == -1;
//    return false;
}

int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%d%d", &nNode, &nEdge);

        edges.clear();
        adjacent.clear();
        adjacent.resize(nNode);
        std::vector<int> vecNodWithNegativeEdge;

        for (int i = 0; i < nEdge; ++i) {
            int from, to, cost;
            scanf("%d%d%d", &from, &to, &cost);
            if (cost < 0) {
                vecNodWithNegativeEdge.push_back(from);
                vecNodWithNegativeEdge.push_back(to);
            }
            int edge_id = edges.size();
            edges.push_back(Edge(from, to, cost));
            adjacent[from].push_back(edge_id);
        }

        if (debug)
            for (const auto & e : edges) 
                printf("%d -> %d (%d)\n", e.from(), e.to(), e.cost());
        
        // unique
        {
            std::sort(vecNodWithNegativeEdge.begin(), vecNodWithNegativeEdge.end());
            auto it = std::unique(vecNodWithNegativeEdge.begin(), vecNodWithNegativeEdge.end());
            vecNodWithNegativeEdge.resize(it-vecNodWithNegativeEdge.begin());
        }


        // node with negative edges and update self with prefix containing self
        bool has_negative_cycle = false;
        for (auto startNode : vecNodWithNegativeEdge) {
            if (hasNegativeCycle(startNode)) {
                has_negative_cycle = true;
                break;
            }
        }

        printf("%spossible\n", has_negative_cycle ? "" : "not ");
    }


    
    return 0;
}
