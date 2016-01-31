#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

const bool debug = false;

struct Edge {
    int _from, _to;
    Edge() { }
    Edge(int from, int to) : _from(from), _to(to) { }
    int from() const { return _from; }
    int to() const { return _to; }
};
const int M = 100000+5;
bool visited_edge[M];
struct Edge edges[M];
int scc[M];
typedef int EdgeId;
std::vector<std::vector<EdgeId> > adj_edge;

bool dfs_scc(int cur, int source) {
    bool reach_source = false;
    for (auto edge_id : adj_edge[cur]) {
        if (not visited_edge[edge_id]) {
            int next = edges[edge_id].to();
            visited_edge[edge_id] = true;
            if (next == source or dfs_scc(next, source)) {      
                reach_source = true;
            }
        }
    }
    if (reach_source)
        scc[cur] = source;
    return reach_source;
}

// visited_cnt >= 2, then not DAG head
int visited_cnt[M];
typedef int NodeId;

void dfs_dag(int cur, const std::vector<std::vector<int> > & dagEdge) {
    ++visited_cnt[cur];
    for (auto next : dagEdge[cur]) {
        if (visited_cnt[next] <= 1)
            dfs_dag(next, dagEdge);
    }
}

int get_dag_id(int id, std::map<int, int> & mapIdToDagId, std::vector<std::vector<int> > & dagEdge) {
    if (not mapIdToDagId.count(id)) {
        int dag_id = dagEdge.size();
        mapIdToDagId.insert(std::make_pair(id, dag_id));
        dagEdge.push_back(std::vector<int>());
    }
    return mapIdToDagId[id];
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int nNode, nEdge;
        scanf("%d%d", &nNode, &nEdge);

        adj_edge.clear();
        adj_edge.resize(nNode+1);
        for (int posEdge = 0; posEdge < nEdge; ++posEdge) {
            int from, to;
            scanf("%d%d", &from, &to);
            edges[posEdge] = Edge(from, to);
            adj_edge[from].push_back(posEdge);
        }
        memset(scc, 0, sizeof(int) * (nNode+1));
        memset(visited_edge, false, sizeof(bool) * nEdge);
        for (int i = 1; i <= nNode; ++i) {
            if (not scc[i]) {
                dfs_scc(i, i);
            }
        }

#if 0
        for (int i = 1; i <= nNode; ++i) {
            printf("%d -> %d\n", i, scc[i] ? scc[i] : i);
        }

        std::vector<std::vector<int> > dagEdge;
        std::map<int, int> mapIdToDagId;
        
        for (int i = 1; i <= nNode; ++i) {
            int from_id = (scc[i]) ? scc[i] : i;
            int from_dag_id = get_dag_id(from_id, mapIdToDagId, dagEdge);
            for (auto edge_id : adj_edge[i]) {
                int to = edges[edge_id].to();
                int to_id = (scc[to]) ? scc[to] : to;
                int to_dag_id = get_dag_id(to_id, mapIdToDagId, dagEdge) ;
                if (to_dag_id != from_dag_id)
                    dagEdge[from_dag_id].push_back(to_dag_id);
            }
        }
#endif
#if 0 

        // unique
        for (int i = 0; i < dagEdge.size(); ++i) {
            auto & v = dagEdge[i];
            std::sort(v.begin(), v.end());
            auto it = std::unique(v.begin(), v.end());
            v.resize(it-v.begin());
            if (debug) {
                printf("%d : ", i);
                for (int next : v)
                    printf(" %d", next);
                printf("\n");
            }
        }


        memset(visited_cnt, 0, sizeof(int) * dagEdge.size());
        for (int i = 0; i < dagEdge.size(); ++i) {
            dfs_dag(i, dagEdge);
        }

        int nDagHead = 0;
        for (int i = 0; i < dagEdge.size(); ++i) {
            if (debug)
                printf("%d with cnt %d\n", i, visited_cnt[i]);
            if (visited_cnt[i] == 1)
                ++nDagHead;
        }
        printf("%d\n", nDagHead);
#endif
    }
    return 0;
}
