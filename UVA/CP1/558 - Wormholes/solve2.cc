#include <cstdio>
#include <climits>
#include <vector>

struct Edge {
    int _from, _to, _cost;
    Edge(int from, int to, int cost) : _from(from), _to(to), _cost(cost) { }
};
typedef int EdgeId;

std::vector<Edge> vecEdge;
std::vector<std::vector<EdgeId> > adjacent;
int nNode, nEdge;

const int M = 1000+5;
const int INF = 0x1<<30;
const int NOT_DEFINED = -1;
int distance[M];
int predecessor[M];

int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%d%d", &nNode, &nEdge);
        vecEdge.clear();
        adjacent.clear();
        adjacent.resize(nNode);
        for (int i = 0; i < nEdge; ++i) {
            int from, to,  cost;
            scanf("%d%d%d", &from, &to, &cost);
            EdgeId edge_id = vecEdge.size(); 
            vecEdge.push_back(Edge(from, to, cost));
            adjacent[from].push_back(edge_id);
        }

        for (int i = 0; i < nNode; ++i) {
            distance[i] = INF;
            predecessor[i] = NOT_DEFINED;
        }
        distance[0] = 0;

        for (int cnt = 0; cnt < nNode-1; ++cnt) {
            for (const auto & e : vecEdge) {
                int from = e._from;
                int to = e._to;
                int cost = e._cost;

                int used_distance = distance[from] + cost;
                if (used_distance < distance[to]) {
                    distance[to] = used_distance;
                    predecessor[to] = from;
                }
            }
        }

        bool has_negative_cycle = false;
        for (const auto & e : vecEdge) {
            if (distance[e._from] + e._cost < distance[e._to]) {
                has_negative_cycle = true;
                break;
            }
        }

        printf("%s\n", has_negative_cycle ? "possible" : "not possible");
    }

    return 0;
}
