#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 1000 + 5;
int a[MAX];
int b[MAX];
int cntA[10];
int cntB[10];

int main() {
    int N;
    int posGame = 1;
    while (scanf("%d", &N) == 1 && N) {
        printf("Game %d:\n", posGame++);
        for (int i = 0; i < N; ++i) { scanf("%d", &a[i]); }
        for (; ;) {

            for (int i = 0; i < N; ++i) { scanf("%d", &b[i]); }
            if (!b[0])
                break;
            int nA = 0, nB = 0;

            memset(cntA, 0, sizeof(cntA));
            memset(cntB, 0, sizeof(cntB));
            for (int i = 0; i < N; ++i) {
                if (a[i] == b[i]) {
                    ++nA;
                } else {
                    ++cntA[a[i]];
                    ++cntB[b[i]];
                }
            }

            for (int i = 0; i < 10; ++i)
                nB += std::min(cntA[i], cntB[i]);

            printf("    (%d,%d)\n", nA, nB);
        }
        

    }
    return 0;
}
