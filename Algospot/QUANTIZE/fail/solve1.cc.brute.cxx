#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int M = 100+5;
int nData, nVar;

int A[M];
int V[15];

int square(int x) { return x * x; }

int get_closest(int x) {
    auto it = std::lower_bound(V, V+nVar, x);
    if (it == V + nVar) return V[nVar-1];
    else if (it == V) return *it;
    else if (*it == x) return x;

    int now = *it;
    int prev = *(--it);
    if (abs(prev-x) <= abs(now-x)) return prev;
    return now;
}

void dfs(int cur, int & min_cost) {
    if (cur >= nVar) {
        int cost = 0;
        for (int i = 0; i < nVar; ++i)
            printf("%d ", V[i]);
        printf("\n");
        for (int i = 0; i < nData; ++i) {
            int now = A[i];
            cost += square(get_closest(now)-now);
        }
        min_cost = std::min(min_cost, cost);
    } else {
        for (int i = (cur == 0) ? 1 : V[cur-1]+1; i <= 1000-(nVar-cur-1); ++i) {
            V[cur] = i;
            dfs(cur+1, nVar);
        }
    }
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &nData, &nVar);

        for (int i = 0; i < nData; ++i) scanf("%d", A+i);
        int min_cost = 1<<29;
        dfs(0, min_cost);
        printf("%d", min_cost);
    }
    return 0;
}
