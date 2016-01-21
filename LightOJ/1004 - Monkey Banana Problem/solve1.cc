#include <cstdio>
#include <cstring>
#include <algorithm>

const int M = 100+5;
int a[2*M][M];
int b[2*M][M];

void print(int A[2*M][M], int N) {
    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k <= i; ++k) {
            printf("%d ", A[i][k]);
        }
        printf("\n");
    }
    for (int i = N+1; i < 2 * N; ++i) {
        for (int k = 1; k <= 2*N-i; ++k) {
            printf("%d ", A[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int nCase, posCase = 1, N;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &N);

        memset(b, 0, sizeof(b));
        for (int i = 1; i <= N; ++i)
            for (int k = 1; k <= i; ++k) { 
//                printf("%d %d\n", i, k);
                scanf("%d", &a[i][k]);
            }
        for (int i = N+1; i < 2 * N; ++i)
            for (int k = 1; k <= 2*N-i; ++k) {
//                printf("%d %d\n", i, k);
                scanf("%d", &a[i][k]);
            }
//        print(a, N);
        b[1][1] = a[1][1]; 
        for (int i = 1; i < N; ++i) 
            for (int k = 1; k <= i; ++k) {
                b[i+1][k] = std::max(b[i+1][k], b[i][k] + a[i+1][k]);
                b[i+1][k+1] = std::max(b[i+1][k+1], b[i][k] + a[i+1][k+1]);
            }
        for (int i = N+1; i < 2 * N; ++i)
            for (int k = 1; k <= 2 * N - i; ++k) {
                b[i][k] = std::max(b[i-1][k], b[i-1][k+1]) + a[i][k];
            }
//        print(b, N);
        printf("Case %d: %d\n", posCase++, b[2*N-1][1]);
    }
    return 0;
}
