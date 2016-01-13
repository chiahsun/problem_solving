#include <cstdio>
#include <cmath>

int main() {
    int R, N;
    int posCase = 1;
    while (scanf("%d%d", &R, &N) == 2 and R) {
        int sz = 0;
        if (R-N > 0) {
            sz = (R-N)/N;
            if (sz * N != (R-N)) ++sz;
        }
        printf("Case %d: ", posCase++);
        if (sz <= 26)
            printf("%d\n", sz);
        else
            printf("impossible\n");
    }
    return 0;
}
