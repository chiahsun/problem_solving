#include <cstdio>
#include <cstring>
#include <algorithm>

int nnode;

const int M = 100+5;
int nedge[M];
int edge[M][M];
char buf[300];
bool visited[M];

void dfs(int cur, int critical, int & other_cnt, const int & nother) {
    visited[cur] = true;
    for (int i = 0; i < nedge[critical]; ++i)
        if (cur == edge[critical][i]) {
    //        printf("++other_cnt at %d\n", cur);
            ++other_cnt;
            break;
        }
    if (other_cnt == nother)
        return;
    for (int i = 0; i < nedge[cur]; ++i) {
        int next = edge[cur][i];
        if (not visited[next] and next != critical)
            dfs(next, critical, other_cnt, nother);
    }

}


// from one node in other, all other should be reachable
bool remove_then_fail(int critical) {
    int nother = nedge[critical];
    if (nother == 0 or nother == 1)
        return false;

    int other_cnt = 0;
    memset(visited, false, sizeof(visited));
    dfs(edge[critical][0], critical, other_cnt, nother);
#if 0
    if (other_cnt != nother)
        printf("fail at %d with other_cnt %d, nother %d\n", critical, other_cnt, nother);
#endif
    return (other_cnt != nother);
}

int main() {
    while (scanf("%d", &nnode) == 1 and nnode) {
        while (getchar() != '\n') {}
        memset(nedge, 0, sizeof(nedge));
        while (scanf("%[^\n]", buf) == 1) {
            getchar();
            int len, central;
            sscanf(buf, "%d%n", &central, &len);
            if (central == 0)
                break;
            int pos = len, other;
            while (sscanf(buf+pos, "%d%n", &other, &len) == 1) {
                edge[central][nedge[central]++] = other;
                edge[other][nedge[other]++] = central;
                pos += len;
            }
        }

        for (int i = 1; i <= nnode; ++i) {
            std::sort(edge[i], edge[i]+nedge[i]);
            auto it = std::unique(edge[i], edge[i]+nedge[i]);
            nedge[i] = it-edge[i];
#if 0
            printf("%d : ", i);
            for (int k = 0; k < nedge[i]; ++k)
                printf(" %d", edge[i][k]);
            printf("\n");
#endif
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
