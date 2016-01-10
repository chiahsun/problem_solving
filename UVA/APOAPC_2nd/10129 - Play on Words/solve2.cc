#include <cstdio>
#include <cassert>
#include <cstring>

const int M = 26+1;
int edge[M][M];
int in_edge_cnt[M];
int out_edge_cnt[M];
char buf[1000+5];

int get_id(char c) { return c - 'a' + 1; }

void dfs(const int & start_terminal, const int & end_terminal, int cur, int & edge_cnt) {
    for (int i = 1; i <= 26; ++i) {
        if (i != end_terminal and edge[cur][i] > 0) {
            --edge[cur][i];
            --edge_cnt;
            dfs(start_terminal, end_terminal, i, edge_cnt);
        }
    }
    if (edge[cur][end_terminal]) {
        --edge[cur][end_terminal];
        --edge_cnt;
        dfs(start_terminal, end_terminal, end_terminal, edge_cnt);
    }
}

void dfs2(int & cur, int & edge_cnt) {
    for (int i = 1; i <= 26; ++i) {
        if (edge[cur][i] > 0) {
            --edge[cur][i];
            --edge_cnt;
            cur = i;
            dfs2(cur, edge_cnt);
        }
    }
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int nWord;
        scanf("%d", &nWord);
        memset(edge, 0, sizeof(edge));
        memset(in_edge_cnt, 0, sizeof(in_edge_cnt));
        memset(out_edge_cnt, 0, sizeof(out_edge_cnt));
        int edge_cnt = 0;

        while (nWord--) {
            scanf("%s", buf);
            int len = strlen(buf);
            int from = get_id(buf[0]);
            int to = get_id(buf[len-1]);
            ++edge[from][to];
            ++out_edge_cnt[from];
            ++in_edge_cnt[to];
            ++edge_cnt;
        }

        bool ok = true;
        int start_terminal = 0, end_terminal = 0;
        int root = 0;
#if 0
        for (int i = 1; i <= 26; ++i)
            if (in_edge_cnt[i] != 0 or out_edge_cnt[i] != 0)
                printf("%c: in(%d), out(%d)\n", i+'a'-1, in_edge_cnt[i], out_edge_cnt[i]);
#endif
        for (int i = 1; ok and i <= 26; ++i) {
            if (in_edge_cnt[i] > out_edge_cnt[i]) {
                if (in_edge_cnt[i] == (out_edge_cnt[i]+1) and (not end_terminal)) 
                    end_terminal = i;
                else
                    ok = false;
            } else if (in_edge_cnt[i] < out_edge_cnt[i]) {
                if (out_edge_cnt[i] == (in_edge_cnt[i]+1) and (not start_terminal)) 
                    start_terminal = i;
                else
                    ok = false;
            } else {
                if ((not root) and out_edge_cnt[i] != 0)
                    root = i;
            }
        }
//        printf("start : %c, end : %c, root : %c\n", start_terminal+'a'-1, end_terminal+'a'-1, root+'a'-1);

        if (start_terminal and (not end_terminal)) ok = false;
        if (end_terminal and (not start_terminal)) ok = false;


        if (ok) {
            if (start_terminal)
                dfs(start_terminal, end_terminal, start_terminal, edge_cnt);
            else {
                assert(root);
                dfs2(root, edge_cnt);
            }
        }

        ok = ok and (edge_cnt == 0);
        printf("%s\n", (ok ? "Ordering is possible." : "The door cannot be opened."));
    }
    return 0;
}
