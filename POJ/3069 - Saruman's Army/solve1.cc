#include <cstdio>
#include <algorithm>

const bool debug = false;
const int M = 1000+5;
int A[M];

const int INF = 1000 + 1000 + 500;
int main() {
    int range, nTroop;
    while (scanf("%d%d", &range, &nTroop) == 2 and range >= 0)  {
        for (int i = 0; i < nTroop; ++i) scanf("%d", A+i);
        std::sort(A, A+nTroop);

        if (debug) {
            for (int i = 0; i < nTroop; ++i) printf("%d ", A[i]); 
            printf("\n");
        }

        int left_not_convered = 0;
        int n_select = 0;
        for (int i = 0; i < nTroop; ++i) {
            int cur = A[i];
            int cur_effect_right = cur + range;
            int next_effect_left = (i+1 < nTroop) ? (A[i+1] - range) : INF;
            if (next_effect_left > A[left_not_convered]) {
                if (debug)
                    printf("choose %d left %d right %d\n", cur, cur - range, cur + range);
                ++n_select;
                while (left_not_convered < nTroop and A[left_not_convered] <= cur_effect_right) {
                    ++left_not_convered;
                }
                i = left_not_convered - 1;
            } 
        }
        printf("%d\n", n_select);
    }
    return 0;
}
