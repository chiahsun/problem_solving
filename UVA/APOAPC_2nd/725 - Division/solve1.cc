#include <cstdio>
#include <cstring>

int cnt[10];
const int M = 100000;
bool valid(int x, int y) {
    if (x >= M or y >= M)
        return false;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 5; ++i) {
        int vx = x % 10; cnt[vx] += 1; x /= 10;
        int vy = y % 10; cnt[vy] += 1; y /= 10;
        if (cnt[vx] > 1) return false;
        if (cnt[vy] > 1) return false;
    }
    return true;
}

int main() {
    bool first = true;
    int N;
    while (scanf("%d", &N) == 1 and N) {
        if (first) first = false;
        else       printf("\n");

        bool found = false;
        for (int f = 0; f <= 4; ++f)
        for (int g = 0; g < 10; ++g)
            if (g != f) {
            for (int h = 0; h < 10; ++h)
                if (h != f and h != g) {
                for (int i = 0; i < 10; ++i)
                    if (i != f and i != g and i != h) {
                    for (int k = 0; k < 10; ++k)
                        if (k != f and k != g and k != h and k != i) {
                            int de = (10 * (10 * (10 * ((10 * f) + g) + h) + i) + k);
                            int nu = N * de;
                            if (valid(nu, de)) {
                                printf("%d / %s%d = %d\n", nu, (de < 10000) ? "0" : "", de, N);
                                found = true;
                            }
                        }
                    }
                }
            }
        if (not found)
            printf("There are no solutions for %d.\n", N);
    }
    return 0;
}
