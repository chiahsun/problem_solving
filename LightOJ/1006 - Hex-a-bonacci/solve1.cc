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
        if (N < M)
            sum = f[N];
        else {
            for (int i = M; i <= N; ++i) {
                sum = 0;
                for (int i = 0; i < M; ++i)
                    sum += f[i];
                for (int i = 0; i < M-1; ++i)
                    f[i] = f[i+1];
                sum %= MOD;
                f[M-1] = sum;
            }
        }
        printf("Case %d: %d\n", posCase++, sum);
    }
    return 0;
}
