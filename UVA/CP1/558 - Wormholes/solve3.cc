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
const int INF = INT_MAX;
const int NOT_DEFINED = -1;
int distance[M];
int predecessor[M];

char buf[500];

int get_line() {
    static int posLine = 1;
    fgets(buf, sizeof(buf), stdin);
    return posLine++;
}

int main() {
    int nCase, posCase = 1;

    get_line();
    sscanf(buf, "%d", &nCase);

    while (nCase--) {
        int startLine = get_line();
        sscanf(buf, "%d%d", &nNode, &nEdge);
        vecEdge.clear();
        adjacent.clear();
        adjacent.resize(nNode);

        std::vector<int> vecSelfLoop;
        
        for (int i = 0; i < nEdge; ++i) {
            int from, to,  cost;
            get_line();
            sscanf(buf, "%d%d%d", &from, &to, &cost);
            if (from == to) 
                vecSelfLoop.push_back(from);
            
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

                int used_distance = distance[from] == INF ? INF : (distance[from] + cost);
                if (used_distance < distance[to]) {
                    distance[to] = used_distance;
                    predecessor[to] = from;
                }
            }
        }

        bool has_negative_cycle = false;
        for (const auto & e : vecEdge) {
            int from = e._from;
            int to = e._to;
            int cost = e._cost;
            if (distance[from] != INF and  (distance[from] + cost < distance[to])) {
                has_negative_cycle = true;
                break;
            }
        }

        for (int i = 1; i < nNode; ++i)
            if (distance[i] == INF)
                printf("Case %d (line:%d): %d is not reachable from 0\n", posCase, startLine, i);
        for (const auto x : vecSelfLoop)
            printf("Case %d (line:%d): %d has self loop\n", posCase, startLine, x);

        posCase++;

        printf("%s\n", has_negative_cycle ? "possible" : "not possible");
    }

    return 0;
}
