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
        for (int f = 0; f <= 4; ++f) {
            int sum1 = f;
            if (sum1 * N * 10000 >= M)
                break;
            for (int g = 0; g < 10; ++g) {
                int sum2 = sum1 * 10 + g;
                if (sum2 * N * 1000 >= M)
                    break;
                if (g == f) 
                    continue;
                for (int h = 0; h < 10; ++h) {
                    int sum3 = sum2 * 10 + h;
                    if (sum3 * N * 100 >= M)
                        break;
                    if (h == g or h == f) 
                        continue;
                    for (int i = 0; i < 10; ++i) {
                        int  sum4 = sum3 * 10 + i;
                        if (sum4 * N * 10 >= M)
                            break;
                        if (i == f or i == g or i == h)
                            continue;
                        for (int k = 0; k < 10; ++k) {
                            int de = 10 * sum4 + k;
                            int nu = N * de;
                            if (valid(nu, de)) {
                                printf("%d / %s%d = %d\n", nu, (de < 10000) ? "0" : "", de, N);
                                found = true;
                            }
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
