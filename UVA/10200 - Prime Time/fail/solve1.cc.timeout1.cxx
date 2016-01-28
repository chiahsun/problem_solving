#include <cstdio>
#include <cstring>
#include <algorithm>
const int M = 10000+5;
int a[M];

bool is_prime(int x) {
    if (x < M) return a[x];
    if (x % 2 == 0) return false;
    for (int i = 3; i < M; i += 2) 
        if (a[i] and (x % i == 0))
            return false;
    return true;
}

void compute_prime() {
    memset(a, true, sizeof(a));
    a[0] = a[1] = false;
    for (int i = 2+2; i < M; i += 2)
        a[i] = false;
    for (int i = 3; i < M; i+=2)
        if (a[i])
            for (int k = i+i+i; k < M; k+=(2*i))
                a[k] = false;
#if 0
    for (int i = 0; i < 100; ++i)
        if (a[i])
            printf("%d ", i);
#endif
}

int main() {
    compute_prime();

    int from, to;
    while (scanf("%d%d", &from, &to) == 2) {
        int nprime = 0;
        for (int i = from; i <= to; ++i)
            if (is_prime(i*i+i+41))
                ++nprime;
        printf("%.2lf\n", (double)nprime * 100/(to-from+1) + 1E-6);
    }

    return 0;
}
