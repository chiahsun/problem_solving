#include <cstdio>

const int M = 100+5;
int a[M][M];

int main() {

    int N;
    while (scanf("%d", &N) == 1 and N) {
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k) {
                scanf("%d", &a[i][k]);
            }
        bool ok = true;
        int pRow = -1, pCol = -1;
        for (int i = 0; i < N; ++i) {
            int sum1 = 0, sum2 = 0;
            for (int k = 0; k < N; ++k) {
                sum1 += a[i][k];
                sum2 += a[k][i];
            }
            if (sum1 % 2 != 0) {
                if (pRow >= 0) {
                    ok = false;
                    break;
                } else {
                    pRow = i;
                }
            }
            if (sum2 % 2 != 0) {
                if (pCol >= 0) {
                    ok = false;
                    break;
                } else {
                    pCol = i;
                }
            }
        }
        if (ok) {
            if (pRow >= 0 and pCol >= 0) {
                printf("Change bit (%d,%d)\n", pRow+1, pCol+1);
            } else if (pRow < 0 and pCol < 0) {
                printf("OK\n");
            } else
                ok = false;
        }
        if (not ok)
            printf("Corrupt\n");
    }

    return 0;
}
