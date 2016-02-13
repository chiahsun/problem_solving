#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>

const bool debug = false;

const int M = 100+5;
int nData, nVar;

int A[M];
int prefix_sum[M];
int prefix_square_sum[M];
int computed[101+5][101+5];
int dp[M][10+5];

int square(int x) { return x * x; }

int get_cost(int begin, int end) {
    assert(begin < end);
    if (computed[begin][end] == -1) {
        // int medium = (double)(prefix_sum[end]-prefix_sum[begin])/(end-begin) + 0.5;
        int medium = (double)(prefix_sum[end]-prefix_sum[begin])/(end-begin) + 0.5+10E-6;
        
        int cost = prefix_square_sum[end]-prefix_square_sum[begin];
        cost -= 2 * medium * (prefix_sum[end] - prefix_sum[begin]);
        cost += medium * medium * (end - begin);
        computed[begin][end] = cost;
    }
    return computed[begin][end];
}

int solve(int start, int chance) {
    assert(start < nData);
//    if (start >= nData) return 0;
    if (dp[start][chance] == -1) {
        int vmin = get_cost(start, nData);
        if (chance > 1) {
            // for (int end = start+1; end < nData-(chance-1); ++end)  // bug
            for (int end = start+1; end <= nData-(chance-1); ++end) 
            // for (int end = start+1; end <= nData; ++end) 
                vmin = std::min(vmin, get_cost(start, end) + solve(end, chance-1));
        }
        dp[start][chance] = vmin;
    }
    return dp[start][chance];
}


int main() {

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &nData, &nVar);
        for (int i = 0; i < nData; ++i) scanf("%d", A+i);

        if (nData > nVar) {
            std::sort(A, A+nData);
#if 1 
            std::fill(&computed[0][0], &computed[0][0]+sizeof(computed)/sizeof(computed[0][0]), -1);
            std::fill(&dp[0][0], &dp[0][0]+sizeof(dp)/sizeof(dp[0][0]), -1);
#endif

            prefix_sum[0] = prefix_square_sum[0] = 0;
            for (int i = 0; i < nData; ++i) { 
                prefix_sum[i+1] = prefix_sum[i] + A[i];
                prefix_square_sum[i+1] = prefix_square_sum[i] + A[i] * A[i];
            }
            
            printf("%d\n", solve(0, nVar));
        } else {
            printf("0\n");
        }

    }
    return 0;
}
