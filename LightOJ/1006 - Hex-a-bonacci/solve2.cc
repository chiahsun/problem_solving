#include <cstdio>

const int M = 6;
const int MOD = 10000007;
int main() {
    int nCase, posCase = 1, N;
    scanf("%d", &nCase);
    while (nCase--) {
        int f[M];
        for (int i = 0; i < M; ++i) {
            int x;
            scanf("%d", f + i);
            f[i] %= MOD;
        }
        scanf("%d", &N);
        int sum = 0;
        for (int i = 0; i < M; ++i)
            sum += f[i];
        sum %= MOD;
        if (N < M) {
            sum = f[N];
        } else if (N > M) {
            int prev = f[0];
            for (int i = 0; i < M-1; ++i)
                f[i] = f[i+1];
            f[M-1] = sum;
#if 0
            for (int i = 0; i < M; ++i)
                printf("%d ", f[i]);
            printf("\n");
#endif
            for (int i = M+1; i <= N; ++i) {
                sum = (MOD + 2 * f[M-1] - prev) % MOD;
                prev = f[0];
                for (int i = 0; i < M-1; ++i)
                    f[i] = f[i+1];
                f[M-1] = sum;
#if 0
                for (int i = 0; i < M; ++i)
                    printf("%d ", f[i]);
                printf("\n");
#endif
            }
        }
        printf("Case %d: %d\n", posCase++, sum);
    }
    return 0;
}
