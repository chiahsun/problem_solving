#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
int N, other, nDepend;

// Most depended is the dest
std::map<int, std::set<int> > mapSrc;
std::map<int, std::set<int> > mapDst;

const int M = 100+5;
bool visited[M];
int src_cnt[M];

void dfs(int now, std::vector<int> & vecRoots) {
    visited[now] = true;
    if (mapDst.count(now)) {
        for (const auto & dst : mapDst[now]) {
            if (not visited[dst]) {
                dfs(dst, vecRoots);
            }
        }
    } else {
        vecRoots.push_back(now);
    }
}

void get_src_cnt(int now) {
    if (mapSrc.count(now)) {
        int sum = 0;
        for (const auto & src : mapSrc[now]) {
            if (src_cnt[src] == 0)
                get_src_cnt(src);
            sum += src_cnt[src];
        }
        src_cnt[now] = sum;
    } else {
        src_cnt[now] = 1;
    }
}

struct CntCompare {
    bool operator () (int a, int b) const {
        if (src_cnt[a] != src_cnt[b]) return src_cnt[a] > src_cnt[b];
        return a < b;
    }
};
// get TP order from root to terminal
int main() {
    while (scanf("%d", &N) == 1 and N) {
        mapSrc.clear();
        mapDst.clear();
        for (int pos = 1; pos <= N; ++pos) {
            scanf("%d", &nDepend);
            while (nDepend--) {
                scanf("%d", &other);
                mapSrc[pos].insert(other);
                mapDst[other].insert(pos);
            }
        }
        memset(visited, false, sizeof(visited));
        std::vector<int> vecRoots;
        for (int now = 1; now <= N; ++now) {
            if (not visited[now]) {
                dfs(now, vecRoots);
            }
        }
        memset(src_cnt, 0, sizeof(src_cnt));
        for (int i = 0; i < vecRoots.size(); ++i) {
           get_src_cnt(vecRoots[i]);
        //    printf("%d\n", vecRoots[i]);
        }
        std::sort(vecRoots.begin(), vecRoots.end(), CntCompare());
        // printf("%d with cnt %d\n", vecRoots[0], src_cnt[vecRoots[0]]);
        printf("%d\n", vecRoots[0]);
    }
    return 0;
}
