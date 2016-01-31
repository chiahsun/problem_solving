#include <cstdio>
#include <vector>
#include <queue>


struct Edge { 
    int _to, _cost;
    Edge(int to, int cost) : _to(to), _cost(cost) { }
    int to() const { return _to; }
    int cost() const { return _cost; }
};

struct Now {
    int _position, _distance;
    Now(int position, int distance) : _position(position), _distance(distance) { }
    int position() const { return _position; }
    int distance() const { return _distance; }
    bool operator < (const Now & rhs) const { return distance() > rhs.distance(); }
};

const int M = 20000+5;
std::vector<Edge> edges[M];

const int UNREACHABLE = -1;
int distance[M];

int main() {
    int nCase, posCase = 1;
    scanf("%d", &nCase);
    int nNode, nEdge, src, dst;
    while (nCase--) {
        scanf("%d%d%d%d", &nNode, &nEdge, &src, &dst);
        for (int i = 0; i <= nNode; ++i) {
            distance[i] = UNREACHABLE;
            edges[i].clear();
        }
        while (nEdge--) {
            int from, to, cost;
            scanf("%d%d%d", &from, &to, &cost);
            edges[from].push_back(Edge(to, cost));
            edges[to].push_back(Edge(from, cost));
        }


        distance[src] = 0;
        std::priority_queue<Now> pq;
        pq.push(Now(src, 0));

        while (not pq.empty()) {
            Now t = pq.top(); pq.pop();
            int cur_position = t.position();
            int cur_distance = t.distance();
            if (distance[dst] != UNREACHABLE and cur_distance > distance[dst]) break;

            for (const auto & e : edges[cur_position]) {
                int next_position = e.to();
                int next_distance = cur_distance + e.cost();
                if (distance[next_position] == UNREACHABLE or distance[next_position] > next_distance)  {
                    distance[next_position] = next_distance;
                    pq.push(Now(next_position, next_distance));
                }
            }
        }

        printf("Case #%d: ", posCase++);
        if (distance[dst] == UNREACHABLE)
            printf("unreachable\n");
        else
            printf("%d\n", distance[dst]);
    }

    return 0;
}
