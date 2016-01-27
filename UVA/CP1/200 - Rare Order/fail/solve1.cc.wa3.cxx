#include <cstdio>
#include <cstring>
#include <cassert>
#include <list>
#include <vector>
#include <algorithm>

char buf1[25], buf2[25];

int nchar_id;
char char_id[26+5];

const int NOT_FOUND = -1;
int get_id(char c) {
    for (int i = 0; i < nchar_id; ++i)
        if (char_id[i] == c)
            return i;
    return NOT_FOUND;
}

void set_id(char c) {
    char_id[nchar_id++] = c;
}

int nedge[26+5];
int edges[26+5][26+5];
bool visited[26+5];

void dfs(int cur, std::list<int> & tp_order) {
    visited[cur] = true;
    for (int i = 0; i < nedge[cur]; ++i) {
        int next = edges[cur][i];
        if (not visited[next])
            dfs(next, tp_order);
    }
    tp_order.push_front(cur);
}

void init() {
    nchar_id = 0;
    memset(nedge, 0, sizeof(nedge));
    memset(visited, false, sizeof(visited));
}

int main() {
    init();
    scanf("%s", buf1); 
    int prev_len = strlen(buf1);
    while (scanf("%s", buf2) == 1 and buf2[0] != '#') {
        int cur_len = strlen(buf2);
        for (int i = 0; i < std::min(prev_len, cur_len); ++i) {
            char fst = buf1[i];
            char snd = buf2[i];
            if (fst != snd) {
                if (NOT_FOUND == get_id(fst)) {
                    set_id(fst);
                    // printf("set id for %c : %d\n", fst, get_id(fst));
                }
                if (NOT_FOUND == get_id(snd)) {
                    set_id(snd);
                    // printf("set id for %c : %d\n", snd, get_id(snd));
                }
                //                    printf("%c -> %c\n", fst, snd);
                int fst_id = get_id(fst); assert(fst_id >= 0);
                int snd_id = get_id(snd); assert(snd_id >= 0);
                edges[fst_id][nedge[fst_id]++] = snd_id;
                break;
            }
        }
        strcpy(buf1, buf2);
        prev_len = cur_len;
    }

#if 0
    // unique for edges
    for (int i = 0; i < nchar_id; ++i) {
        std::sort(edges[i], edges[i]+nedge[i]);
        auto it = std::unique(edges[i], edges[i]+nedge[i]);
        nedge[i] = it - edges[i];
    }
#endif

    std::list<int> tp_order;
#if 1
    for (int i = 0; i < nchar_id; ++i) {
        if (not visited[i] and char_id[i] <= 'Z' and char_id[i] >= 'A')
            dfs(i, tp_order);
    }
#endif 
    for (auto id : tp_order) {
        assert(id >= 0 and id < nchar_id);
        printf("%c", char_id[id]);
    }
    printf("\n");


    return 0;
}
