#include <cstdio>
#include <cstring>
#include <algorithm>

const int M = 300;

int table[M+1][M+1];

int get_cost(int x, int y) {
    if (x > y) return get_cost(y, x);
    if (x == 1) return y-1;

    if (table[x][y] != 0) return table[x][y];

    int cost = M * M;
    for (int i = 1; i <= x/2; ++i) 
        cost = std::min(cost, 1 + get_cost(i, y) + get_cost(x-i, y));
    for (int k = 1; k <= y/2; ++k) 
        cost = std::min(cost, 1 + get_cost(x, k) + get_cost(x, k-k));
    return (table[x][y] = cost);
}


int main() {
    memset(table, 0, sizeof(table));
    
    int x, y;
    while (scanf("%d%d", &x, &y) == 2) {
        printf("%d\n", get_cost(x, y));
    }
    return 0;
}
