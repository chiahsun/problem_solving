#include <cstdio>
#include <queue>
#include <set>
#include <map>

// Improvement: use hash
std::map<int, std::set<int> > mapEdge;
std::set<int> setNode;
std::set<int> setVisited;

int main() {
    int nEdge, posCase = 1;
    while (scanf("%d", &nEdge) == 1 and nEdge) {
        mapEdge.clear();
        setNode.clear();
        while (nEdge--) {
            int from, to;
            scanf("%d%d", &from, &to);
            mapEdge[from].insert(to);
            mapEdge[to].insert(from);
            setNode.insert(to);
            setNode.insert(from);
        }
        int src, ttl;
        // Improvement: use color to avoid add multiple times
        while (scanf("%d%d", &src, &ttl) == 2 and (src != 0 or ttl != 0)) {
            setVisited.clear();
            std::queue<int> q[2];
            q[0].push(src);
            int cur_time = 0;
            while ((not q[0].empty()) or (not q[1].empty())) {
                std::queue<int> & qcur = (q[0].empty()) ? q[1] : q[0];
                std::queue<int> & qnext = (q[0].empty()) ? q[0] : q[1];
                if (cur_time > ttl)
                    break;
                while (not qcur.empty()) {
                    int now = qcur.front(); qcur.pop();
                    if (not setVisited.count(now)) {
                        setVisited.insert(now);
                        for (const auto & adj : mapEdge[now]) {
                            if (not setVisited.count(adj))
                                qnext.push(adj);
                        }
                    }
                }
                ++cur_time;
            }

            printf("Case %d: %lu nodes not reachable from node %d with TTL = %d.\n", posCase++, setNode.size()-setVisited.size() + (not setNode.count(src) ? 1 : 0), src, ttl);
        }

    }
    return 0;
}
