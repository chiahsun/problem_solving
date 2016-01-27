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

std::vector<int> edges[26+5]; // be sure to use vector or list, not to use fixed size !!
bool visited[26+5];
std::list<int> tp_order;

void dfs(int cur) {
    visited[cur] = true;
    for (int i = 0; i < edges[cur].size(); ++i) {
        int next = edges[cur][i];
        if (not visited[next])
            dfs(next);
    }
    tp_order.push_front(cur);
}


int main() {
    nchar_id = 0;
    memset(visited, false, sizeof(visited));
    scanf("%s", buf1); 
    int prev_len = strlen(buf1);
    while (scanf("%s", buf2) == 1 and buf2[0] != '#') {
        int cur_len = strlen(buf2);
        for (int i = 0; i < std::min(prev_len, cur_len); ++i) {
            char fst = buf1[i];
            char snd = buf2[i];
            if (fst != snd) {
                if (NOT_FOUND == get_id(fst)) 
                    set_id(fst);
                if (NOT_FOUND == get_id(snd)) 
                    set_id(snd);
                //                    printf("%c -> %c\n", fst, snd);
                int fst_id = get_id(fst);
                int snd_id = get_id(snd);
                edges[fst_id].push_back(snd_id);
                break;
            }
        }
        strcpy(buf1, buf2);
        prev_len = cur_len;
    }

    // unique for edges
    for (int i = 0; i < nchar_id; ++i) {
        std::sort(edges[i].begin(), edges[i].end());
        auto it = std::unique(edges[i].begin(), edges[i].end());
        edges[i].resize(it - edges[i].begin());
    }

    for (int i = 0; i < nchar_id; ++i) 
        if (not visited[i])
            dfs(i);
    
    for (auto i : tp_order)
        printf("%c", char_id[i]);
    
    printf("\n");

    return 0;
}
