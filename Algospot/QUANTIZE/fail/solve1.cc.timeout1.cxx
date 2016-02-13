#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>

const bool debug = !false;

const int M = 100+5;
int nData, nVar;

int A[M];
int V[15];
int square(int x) { return x * x; }

double nth_root(double A, int nth) {
    double x = A, dx = 10;
    while (fabs(dx) > 0.01) {
        dx = (A/pow(x, nth-1) - x)/nth;
        x = x + dx;
    }
    return x;
}

int nth_root_rounded(double A, int nth) {
    return (nth_root(A, nth)+0.5+10E-6);
}

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

int get_root(int begin, int end) {
    double res = 1;
    for (int i = begin; i < end; ++i) 
        res *= A[i];
    return nth_root_rounded(res, end-begin);
}

int get_cost(int begin, int end, int pivot) {
    assert(end > begin);
    double cost = 0;
    for (int i = begin; i < end; ++i)
        cost += square(pivot-A[i]);
    return cost;
}

void dfs(int cur, const int & nSplit, int & min_cost) {
    if (cur >= nSplit) {
#if 0 
        for (int i = 0, pos = 0; i < nData; ++i) {
            if (pos < nSplit and V[pos] == i) {
                printf("| ");
                ++pos;
            }
            printf("%d ", A[i]);
        }
        printf("  ");
#endif
#if 1 
        int cost = 0;
        for (int i = 0; i <= nSplit; ++i) {
            int begin = (i == 0) ? 0 : V[i-1];
            int end = (i == nSplit) ? nData : V[i];

            int cur_min_cost = 1 << 29;
            for (int k = A[begin]; k <= A[end-1]; ++k) {
                cur_min_cost = std::min(cur_min_cost, get_cost(begin, end, k));
            }
            cost += cur_min_cost;
        }
        min_cost = std::min(min_cost, cost);
#endif
    } else {
        for (int i = (cur == 0) ? 1 : (V[cur-1]+1); i < nData-(nSplit-cur)+1; ++i) {
            V[cur] = i;
            dfs(cur+1, nSplit, min_cost);
        }
    }
}

int main() {
#if 0
    {
        int nth = 4;
        int i = pow(3, nth);
        double root = nth_root(i, nth);
        printf("nth_root(%d, %d) : %lf(%lf)  -> %d\n", i, nth, root, pow(root, nth), nth_root_rounded(i, nth));
        return 0;
    }
    for (int i = 1; i < 100; ++i) {
        int nth = 3;
        double root = nth_root(i, nth);
        printf("nth_root(%d, %d) : %lf(%lf)  -> %d\n", i, nth, root, pow(root, nth), nth_root_rounded(i, nth));
    }
    return 0;
#endif

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &nData, &nVar);

        if (nData > nVar) {
            for (int i = 0; i < nData; ++i) scanf("%d", A+i);
            std::sort(A, A+nData);
            int nSplit = nVar-1, min_cost = 1<<29;

            dfs(0, nSplit, min_cost);
            printf("%d\n", min_cost);
        } else {
            printf("0\n");
        }

    }
    return 0;
}
