#include <cstdio>
#include <cassert>
#include <cstring>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

const bool debug = false;
const int NOT_REACHABLE = -1;

const int M = 100 + 5;
int maxflow[M][M];
std::map<int, std::map<int, int> > mapWeight;

void add_weight(int from, int to, int weight) {
    mapWeight[from][to] = mapWeight[to][from] = weight;
}

int get_weight(int from, int to) {
    assert(mapWeight.count(from));
    assert(mapWeight[from].count(to));
    return mapWeight[from][to];
}


struct Cur {
    int _fromCity, _curCity, _weight;
    Cur(int fromCity, int curCity, int weight) : _fromCity(fromCity), _curCity(curCity), _weight(weight) { }
    int getFromCity() const { return _fromCity; }
    int getCurCity() const { return _curCity; }
    int getWeight() const { return _weight; }
};

struct WeightCompare {
    const bool operator () (const Cur & lhs, const Cur & rhs) const
      { return lhs.getWeight() < rhs.getWeight(); }
};

int main() {
    int nCity, nRoad, posCase = 1;
    while (scanf("%d%d", &nCity, &nRoad) == 2 and nCity) {
        mapWeight.clear();
        memset(maxflow, NOT_REACHABLE, sizeof(maxflow));
        for (int i = 0; i < M; ++i) maxflow[i][i] = 0;

        for (int i = 0; i < nRoad; ++i) {
            int from, to, weight;
            scanf("%d%d%d", &from, &to, &weight);
            add_weight(from, to, weight);
        }
        int srcCity, destCity, nPassenger;
        scanf("%d%d%d", &srcCity, &destCity, &nPassenger);
        if (srcCity == destCity) {
            printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", posCase++, 1);
            continue;
        }

        std::priority_queue<Cur, std::vector<Cur>, WeightCompare> q;
            for (const auto & pr : mapWeight[srcCity])
                q.push(Cur(srcCity, pr.first, pr.second));

        int destMaxFlow = 0;
        while (not q.empty()) {
            Cur cur = q.top(); q.pop();
            int fromCity = cur.getFromCity();
            int curCity = cur.getCurCity();
            if (cur.getWeight() <= destMaxFlow)
                break;
            int cur_flow = std::min(cur.getWeight(), get_weight(fromCity, curCity));
            int & prev_flow = maxflow[fromCity][curCity];
            if (debug)
                printf("%d -> %d (cur: %d, prev:%d)\n", fromCity, curCity, cur_flow, prev_flow);
            if (prev_flow == NOT_REACHABLE or cur_flow > prev_flow) {
                prev_flow = cur_flow;
                if (debug)
                    printf("    Update flow to %d\n", cur_flow);
                if (curCity == destCity) 
                    destMaxFlow = std::max(destMaxFlow, cur_flow);
                
                for (const auto & pr : mapWeight[curCity]) {
                    int nextCity = pr.first;
                    int nextFlow = std::min(cur_flow, get_weight(curCity, nextCity));
                    if (nextCity != fromCity) {
                        q.push(Cur(curCity, nextCity, nextFlow));
                        if (debug)
                            printf("    Add %d -> %d (%d)\n", curCity, nextCity, nextFlow);
                    }
                }
            }
        }

        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", posCase++, nPassenger/(destMaxFlow-1) + ((nPassenger % (destMaxFlow-1) == 0) ? 0 : 1) );

    }
    return 0;
}
