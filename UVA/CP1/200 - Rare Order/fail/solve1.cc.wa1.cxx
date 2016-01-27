#include <cstdio>
#include <cstring>
#include <list>
#include <algorithm>

int nbook;
char book[1000][25];
int len_book[1000];

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

void update_char_in_book(char cur_book[50], int cur_len) {
    for (int i = 0; i < cur_len; ++i) {
        char cur = cur_book[i];
        if (NOT_FOUND == get_id(cur))
            set_id(cur);
    }
}
void init() {
    nbook = 0;
    nchar_id = 0;
    memset(nedge, 0, sizeof(nedge));
    memset(visited, false, sizeof(visited));
}

int main() {
    init();
    while (scanf("%s", book[nbook]) == 1 and book[nbook][0] != '#') {
        int cur_len = len_book[nbook] = strlen(book[nbook]);
        update_char_in_book(book[nbook], cur_len);
        ++nbook;
        while (scanf("%s", book[nbook]) == 1 and book[nbook][0] != '#') {
            int cur_len = len_book[nbook] = strlen(book[nbook]);
            update_char_in_book(book[nbook], cur_len);
            ++nbook;
        }
    
        for (int i = 1; i < nbook; ++i) {
            int prev_len = len_book[i-1];
            int cur_len = len_book[i];
            for (int k = 0; k < std::min(prev_len, cur_len); ++k) {
                char fst = book[i-1][k];
                char snd = book[i][k];
                if (fst != snd) {
                    // printf("%c -> %c\n", fst, snd);
                    int fst_id = get_id(fst);
                    int snd_id = get_id(snd);
                    edges[fst_id][nedge[fst_id]++] = snd_id;
                    break;
                }
            }
        }

        // unique for edges
        for (int i = 0; i < nchar_id; ++i) {
            std::sort(edges[i], edges[i]+nedge[i]);
            auto it = std::unique(edges[i], edges[i]+nedge[i]);
            nedge[i] = it - edges[i];
        }

        std::list<int> tp_order;
        for (int i = 0; i < nchar_id; ++i) {
            if (not visited[i])
                dfs(i, tp_order);
        }
        for (auto id : tp_order)
            printf("%c", char_id[id]);
        printf("\n");

        init();
    }

    return 0;
}
