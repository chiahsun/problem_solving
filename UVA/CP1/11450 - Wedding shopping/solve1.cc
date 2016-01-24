#include <cstdio>
#include <cstring>
#include <algorithm>

const int M = 200+5;
bool A[M];
bool B[M];

int main() {
    int nCase, money, nGarment;
    scanf("%d", &nCase);
    while (nCase--) {
        memset(A, false, sizeof(A));
        A[0] = true;
        scanf("%d%d", &money, &nGarment);
        int min_cost = 0;
        while (nGarment--) {
            int nModel;
            scanf("%d", &nModel);
            int cur;
            int cur_min = money;
            memcpy(B, A, sizeof(A));
            memset(A, false, sizeof(A));
            while (nModel--) {
                scanf("%d", &cur);
                cur_min = std::min(cur, cur_min);
                for (int i = 0; i <= money; ++i) {
                    if (B[i] and i+cur <= money) {
                        A[i+cur] = true;
                    }
                }
            }
            min_cost += cur_min;
        }
        if (min_cost > money) printf("no solution\n");
        else {
            for (int i = money; i >= 0; --i)
                if (A[i]) {
                    printf("%d\n", i);
                    break;
                }
        }

    }
    return 0;
}
