#include <cstdio>
#include <cstring>

const int M = 1<<8;
bool a[M];
void compute_prime() {
    memset(a, true, sizeof(a));
    a[0] = a[1] = false;
    for (int i = 2+2; i < M; i += 2)
        a[i] = false;
    for (int i = 3; i < M; i += 2) {
        if (a[i]) {
            for (int k = i+i+i; k < M; k += (2*i))
                a[k] = false;
        }
    }
}

bool is_prime(int x) {
    if (x < M)
        return a[x];
    if (x % 2 == 0)
        return false;
    for (int i = 3; i < M; i += 2) {
        if (a[i]) {
            if (x == i)
                return true;
            else if (x % i == 0)
                return false;
        }
    }
    return true;
}

int main() {
    compute_prime();
#if 0
    for (int i = 0; i < 100; ++i)
        if (a[i])
            printf("%d ", i);
#endif
    int x;
    while (scanf("%d", &x) and x) {
        int cnt = 0;
        for (int i = 3; i <= x/2; i += 2) {
            int k = x - i;
            if (is_prime(i) and is_prime(k)) {
//                printf("%d = %d + %d\n", x, i, k);
                ++cnt;
            }
        }
        printf("%d\n", (x >= 6 ? cnt : 1));
    }
    return 0;
}
