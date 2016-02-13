#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>

const bool debug = false;

const int M = 100+5;
int nData, nVar;

int A[M];
int prefix_sum[M];

int V[15];
int square(int x) { return x * x; }

int computed[101+5][101+5];

int get_cost(int begin, int end, int pivot) {
    assert(end > begin);
    double cost = 0;
    for (int i = begin; i < end; ++i)
        cost += square(pivot-A[i]);
    return cost;
}

void dfs(int cur, const int & nSplit, int & min_cost) {
    if (cur >= nSplit) {
        if (debug) {
            for (int i = 0, pos = 0; i < nData; ++i) {
                if (pos < nSplit and V[pos] == i) {
                    printf("| ");
                    ++pos;
                }
                printf("%d ", A[i]);
            }
            printf("\n");
        }
        int cost = 0;
        for (int i = 0; i <= nSplit; ++i) {
            int begin = (i == 0) ? 0 : V[i-1];
            int end = (i == nSplit) ? nData : V[i];
            if (computed[begin][end] == -1) {
                int medium = (double)(prefix_sum[end]-prefix_sum[begin])/(end-begin) + 0.5+10E-6;
                // int medium = (prefix_sum[end]-prefix_sum[begin])/(end-begin);
                computed[begin][end] = get_cost(begin, end, medium);
                if (debug) {
                    printf("    ");
                    for (int k = begin; k < end; ++k) printf("%d ", A[k]);
                    printf(" medium %d -> cost %d\n", medium, computed[begin][end]);
                }
            } 
            cost += computed[begin][end];
        }
        if (debug)
            printf("cost : %d\n", cost);
        min_cost = std::min(min_cost, cost);
    } else {
        for (int i = (cur == 0) ? 1 : (V[cur-1]+1); i < nData-(nSplit-cur)+1; ++i) {
            V[cur] = i;
            dfs(cur+1, nSplit, min_cost);
        }
    }
}

int main() {

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &nData, &nVar);

        if (nData > nVar) {
            for (int i = 0; i < nData; ++i) scanf("%d", A+i);
            std::sort(A, A+nData);
            std::fill(&computed[0][0], &computed[0][0]+sizeof(computed)/sizeof(computed[0][0]), -1);
            std::fill(&prefix_sum[0], &prefix_sum[0]+sizeof(prefix_sum)/sizeof(prefix_sum[0]), 0);

            for (int i = 0; i < nData; ++i) 
                prefix_sum[i+1] = prefix_sum[i] + A[i];
            
            int nSplit = nVar-1, min_cost = 1<<29;

            dfs(0, nSplit, min_cost);
            printf("%d\n", min_cost);
        } else {
            printf("0\n");
        }

    }
    return 0;
}
