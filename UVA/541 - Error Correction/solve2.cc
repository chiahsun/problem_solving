#include <cstdio>
#include <cstring>

const int M = 100+5;
bool sumRow[M], sumCol[M];

int main() {

    int N, x;
    while (scanf("%d", &N) == 1 and N) {
        memset(sumRow, 0, sizeof(sumRow));
        memset(sumCol, 0, sizeof(sumCol));

        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k) {
                scanf("%d", &x);
                if (x) {
                    sumRow[i] = !sumRow[i];
                    sumCol[k] = !sumCol[k];
                }
            }

        bool ok = true;
        int pRow = -1, pCol = -1;
        for (int i = 0; i < N; ++i) {
            if (sumRow[i]) {
                if (pRow < 0) pRow = i;
                else { ok = false; break; }
            }
            if (sumCol[i]) {
                if (pCol < 0) pCol = i;
                else { ok = false; break; }
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
