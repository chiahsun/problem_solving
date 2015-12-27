#include <cstdio>
#include <cstring>

const int MAX = 20 +5;
int N;
bool a[MAX];
int ans[MAX];

int next(int x, int step) {
    if (x + step < 0)
        x += N;
    return (x + step) % N;
}

int clockwise(int x) {
    return next(x, -1);
}

int counterclockwise(int x) {
    return next(x, 1);
}

int main() {
    int K, M;
    while (scanf("%d%d%d", &N, &K, &M) == 3 && N) {
        memset(a, 0, sizeof(a));

        int posk = N-1;
        int posm = 0;
        for (int npick = 0; npick < N; ) {
            for (int i = 0; i < K; ) {
                posk = counterclockwise(posk);
                if (!a[posk])
                    ++i;
//                printf("  %d", posk);
            }
            for (int i = 0; i < M; ) {
                posm = clockwise(posm);
                if (!a[posm])
                    ++i;
            }

            if (npick != 0)
                printf(",");
            if (posk == posm) {
                printf("%3d", posk+1);
                ++npick;
            } else {
                printf("%3d%3d", posk+1, posm+1);
                npick += 2;
            }
            a[posk] = a[posm] = true;
            
        }

        printf("\n");
    }
    return 0;
}
