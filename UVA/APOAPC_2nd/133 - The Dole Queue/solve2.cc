#include <cstdio>
#include <cstring>

const int MAX = 20 + 5;
bool a[MAX];
int N;
int next(int now, int d, int nstep) {
    while (nstep--) {
        do { now = (now-1+N+d) % N + 1; } while (a[now]);
    }
    return now;
}
int main() {
    int K, M;
    while (scanf("%d%d%d", &N, &K, &M) == 3 && N) {
        memset(a, 0, sizeof(a));
        int nleft = N;
        int px = N, py = 1;
        while (nleft) {
            px = next(px, 1, K);
            py = next(py, -1, M);
            if (nleft != N) {
                printf(",");
            }
            --nleft;
            printf("%3d", px);
            if (px != py) {
                printf("%3d", py);
                --nleft;
            }
            a[px] = a[py] = true;
        }
        printf("\n");
    }
    return 0;
}
