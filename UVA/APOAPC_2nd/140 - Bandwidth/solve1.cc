#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

const int M = 8 + 5;

struct Node {
    char _edges[M];
    int _nedge;
    void clear() { _nedge = 0; }
    void addEdge(char another) { 
        if (not connect(another))
            _edges[_nedge++] = another; 
    }
    char getEdge(int pos) { assert(pos >= 0 and pos < size()); return _edges[pos]; }
    int size() const { return _nedge; }
    bool connect(char another) const {
        for (int i = 0; i < _nedge; ++i)
            if (_edges[i] == another)
                return true;
        return false;
    }
} nodes[256];

int cnt[26];
char existed[M];
char ordering[M];
bool used[M];
char best_ordering[M];

void search(int depth, int cost, int & min_cost, const int & nNode) {
    for (int i = 0; i < nNode; ++i) {
        if (not used[i]) {
            char cur = existed[i];
            ordering[depth] = cur;
            int cur_cost = 0;
            for (int k = 0; k < depth; ++k)
                if (nodes[cur].connect(ordering[k])) {
                    cur_cost = depth - k;
                    break;
                }
            cost = std::max(cost, cur_cost);
            if (cost < min_cost) {
                if (depth+1 == nNode) {
                    min_cost = cost;
                    for (int i = 0; i < nNode; ++i)
                        best_ordering[i] = ordering[i];
                } else {
                    used[i] = true;
                    search(depth+1, cost, min_cost, nNode);
                    used[i] = false;
                }
            }
        }
    }
}

void solve() {
    int nNode = 0;
    for (int i = 0; i < 26; ++i)
        if (cnt[i]) {
            existed[nNode] = i + 'A';
            ++nNode;
        }
    int min_cost = 26;
    search(0, 0, min_cost, nNode);
    for (int i = 0; i < nNode; ++i)
        printf("%c ", best_ordering[i]);
    printf("-> %d\n", min_cost);
}

char buf[50];

void reset() {
    for (int i = 'A'; i <= 'Z'; ++i)
        nodes[i].clear();
    memset(cnt, 0, sizeof(cnt));
}

int main() {
    reset();
    while (scanf("%[A-Z]", buf) == 1 and buf[0] != '#') {
        char cur = buf[0]; ++cnt[cur-'A'];
        getchar(); // :
        scanf("%[A-Z]", buf);
        for (int i = 0; i < strlen(buf); ++i) {
            char another = buf[i]; ++cnt[another -'A'];
            nodes[cur].addEdge(another);
            nodes[another].addEdge(cur);
        }
        char c = getchar();
        if (c == '\n') {
            solve();
            reset();
        }
    }
    return 0;
}
