#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

int nnode;

const int M = 100+5;
char buf[300];
bool visited[M];
std::map<int, std::set<int> > mapEdge;

void dfs(int cur, int critical, int & other_cnt, const int & nother) {
    visited[cur] = true;
    if (mapEdge[critical].count(cur))
        ++other_cnt;
    if (other_cnt == nother)
        return;
    for (const auto & next : mapEdge[cur]) {
        if (nother == other_cnt)
            break;
        if (not visited[next] and next != critical)
            dfs(next, critical, other_cnt, nother);
    }
}


// from one node in other, all other should be reachable
bool remove_then_fail(int critical) {
    int nother = mapEdge[critical].size();
    if (nother == 0 or nother == 1)
        return false;

    int other_cnt = 0;
    memset(visited, false, sizeof(visited));
    dfs(*(mapEdge[critical].begin()), critical, other_cnt, nother);
    return (other_cnt != nother);
}

int main() {
    while (scanf("%d", &nnode) == 1 and nnode) {
        while (getchar() != '\n') {}
        mapEdge.clear();
        while (scanf("%[^\n]", buf) == 1) {
            getchar();
            int len, central;
            sscanf(buf, "%d%n", &central, &len);
            if (central == 0)
                break;
            int pos = len, other;
            while (sscanf(buf+pos, "%d%n", &other, &len) == 1) {
                mapEdge[central].insert(other);
                mapEdge[other].insert(central);
                pos += len;
            }
        }

        int ncritical = 0;
        for (int i = 1; i <= nnode; ++i)  {
            if (remove_then_fail(i)) {
                // printf("%d is critical\n", i);
                ++ncritical;
            }
        }
        
        printf("%d\n", ncritical);
        
    }

    return 0;
}
