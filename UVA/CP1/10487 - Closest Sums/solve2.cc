#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <algorithm>

const bool debug = false;

const int M = 1000+5;
int A[M];

int find_closest_but_not_exclude(int x, int exclude, int nInt) {
    auto plow = std::lower_bound(A, A+nInt, x);
    auto phigh = std::upper_bound(A, A+nInt, x);

    if (plow == A+nInt) plow = A+nInt-1;
    if (phigh == A+nInt) phigh = A+nInt-1;
    if (debug)
        printf("  find(%d but not %d) plow : %d phigh : %d\n", x, exclude, *plow, *phigh);
    if (x != exclude and *plow == x) return x; 
    if (*plow > x and plow != A) --plow;
    while (*plow == exclude and plow != A) --plow;
    while (*phigh == exclude and phigh + 1  != A+nInt) ++phigh;

    if (*plow == exclude) return *phigh;
    if (*phigh == exclude) return *plow;

    return (abs(*plow-x) <= abs(*phigh-x) ? *plow : *phigh);
}

void update_closest(int z, int x, int target, int & dmin, int & now) {
    if (abs(z+x-target) < dmin) {
        dmin = abs(z+x-target);
        now = z+x;
    }
}

int main() {

    int nInt, target, posCase = 1, nQuery;
    while (scanf("%d", &nInt) == 1 and nInt) {
        for (int i = 0; i < nInt; ++i)
            scanf("%d", A+i);

        std::sort(A,A+nInt);
        auto it = std::unique(A, A+nInt);
        nInt = it - A;
        if (debug) {
            printf("[%d] :", nInt);
            for (int i = 0; i < nInt; ++i)
                printf(" %d", A[i]);
            printf("\n");
        }

        printf("Case %d:\n", posCase++);
        scanf("%d", &nQuery);
        
        while (nQuery--) {
            int dmin = INT_MAX, now = INT_MAX;
            scanf("%d", &target); 
            for (int i = 0; i < nInt; ++i) {
                int x = A[i];
                int y = target - A[i];
                if (debug)
                    printf("now %d try find closest %d\n", x, y);
                int z = find_closest_but_not_exclude(y, x, nInt);
                if (debug)
                    printf("  -> %d\n", z);
                update_closest(z, x, target, dmin, now);
               
                if (dmin == 0) break;
            }


            printf("Closest sum to %d is %d.\n", target, now);
        }

    }
    
    return 0;
}
