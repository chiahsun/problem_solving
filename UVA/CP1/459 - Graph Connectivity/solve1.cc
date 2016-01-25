#include <cstdio>
#include <cstring>

char buf[10];
int edge[26][26];
int nedge[26];

bool visited[26];

void dfs(int cur) {
    if (visited[cur])
        return;
    visited[cur] = true;
    for (int i = 0; i < nedge[cur]; ++i) {
        int next = edge[cur][i];
        if (not visited[next])
            dfs(next);
    }
}

int main() {
    int nCase, len;
    scanf("%d", &nCase);
    bool neof = true;
    while (nCase--) {
        scanf("%s", buf);
        getchar();
        int nNode = buf[0] - 'A' + 1;
        memset(nedge, 0, sizeof(int) * nNode);
        memset(visited, false, sizeof(bool) * nNode);
//        printf("cur : %c\n", buf[0]); 
        while (scanf("%[A-Z]", buf) == 1)  {
            getchar();
            char from = buf[0] - 'A', to = buf[1] - 'A';
            edge[from][nedge[from]++] = to;
            edge[to][nedge[to]++] = from;
//            printf("edge: %c%c\n", buf[0], buf[1]);
        }
        getchar();
        int nGraph = 0;
        for (int i = 0; i < nNode; ++i) {
            if (not visited[i]) {
                ++nGraph;
                dfs(i);
            }
        }
        printf("%d\n%s", nGraph, nCase ? "\n" : "");
    }
    return 0;
}
