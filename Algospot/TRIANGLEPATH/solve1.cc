#include <cstdio>
#include <algorithm>

const int M = 100+5;

int A[M][M];
int B[M][M];

int main() {
    int nCase, N;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            for (int k = 0; k <= i; ++k) {
                scanf("%d", &A[i][k]);
            }

        B[0][0] = A[0][0];
        for (int i = 1; i < N; ++i)
            for (int k = 0; k <= i; ++k) {
                if (k == 0) B[i][k] = A[i][k] + B[i-1][k];
                else B[i][k] = A[i][k] + std::max(B[i-1][k-1], B[i-1][k]);
            }
        int vmax = 0;
        for (int i = 0; i < N; ++i)
            vmax = std::max(vmax, B[N-1][i]);
        printf("%d\n", vmax);
    }
    return 0;
}
