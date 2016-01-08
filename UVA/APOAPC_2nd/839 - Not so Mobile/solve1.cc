#include <cstdio>
#include <cstring>
const bool debug = false;
char buf[100];

const int ROOT = 1;
int posNode;

const int M = 10000;
const int L = 0;
const int R = 1;
int weight[M];
int childs[M][2];
bool equilibrium[M];

int read_tree() {
    int w1, d1, w2, d2;
    scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
    if (debug)
        printf("%d %d %d %d\n", w1, d1, w2, d2);
    int cur = posNode++;
    equilibrium[cur] = true;
    if (not w1) {
        childs[cur][L] = read_tree();
        w1 = weight[childs[cur][L]];
        equilibrium[cur] &= equilibrium[childs[cur][L]];
    }
    if (not w2) {
        childs[cur][R] = read_tree();
        w2 = weight[childs[cur][R]];
        equilibrium[cur] &= equilibrium[childs[cur][R]];
    }
    weight[cur] = w1 + w2;
    equilibrium[cur] &= ((w1 * d1) == (w2 * d2));
    return cur;
}


int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        int posNode = ROOT;
        memset(weight, 0, sizeof(weight));
        memset(childs, 0, sizeof(childs));
        int root = read_tree();
        printf("%s\n", equilibrium[root] ? "YES" : "NO");

        if (nCase)
        printf("\n");
    }
    return 0;
}
