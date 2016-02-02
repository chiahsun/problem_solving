#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>

const bool debug = false;

const int M = 1000+5;
int A[M];
int S[M*M/2];

int main() {

    int nInt, x, posCase = 1, nQuery;
    while (scanf("%d", &nInt) == 1 and nInt) {
        for (int i = 0; i < nInt; ++i)
            scanf("%d", A+i);

        int pos = 0;
        for (int i = 0; i < nInt; ++i)
            for (int k = i+1; k < nInt; ++k) {
                if (A[i] != A[k]) {
                    S[pos++] = A[i] + A[k];
                }
            }

        std::sort(S,S+pos);
#if 0
        for (int i = 0; i < pos; ++i)
            printf("%d ", S[i]);
        printf("\n");
#endif

        printf("Case %d:\n", posCase++);
        scanf("%d", &nQuery);
        
        while (nQuery--) {
            scanf("%d", &x); 
            int dmin = INT_MAX, now = INT_MAX;
            if (debug)
                printf("query : %d\n", x);
            auto plower = std::lower_bound(S, S+pos, x);
            if (*plower != x and plower != S) --plower;
            if (debug)
                printf("plow = %d\n", *plower);
            if (abs(*plower - x) < dmin) {
                dmin = abs(*plower - x);
                now  = *plower;
            }
            auto phigher = std::upper_bound(S, S+pos, x);
            if (debug)
                printf("phigh = %d\n", *phigher);
            if (abs(*phigher - x) < dmin) {
                dmin = abs(*phigher - x);
                now = *phigher;
            }
            printf("Closest sum to %d is %d.\n", x, now);
        }

    }
    
    return 0;
}
