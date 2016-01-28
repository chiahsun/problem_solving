#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>

const int M = 10000+5;
int a[M];
int nprime[M];
// Reference:
// http://stackoverflow.com/questions/1538644/c-determine-if-a-number-is-prime
bool is_prime(int x) {
    if (x < M) return a[x];
    if (x % 2 == 0 or x % 3 == 0) return false;
    for (int i = 5; i*i <= x; i += 6) 
        if (x % i == 0 or x % (i+2) == 0)
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

void compute_formula() {
    nprime[0] = 1;  // 41 is prime
    for (int i = 1; i < M; ++i) {
        nprime[i] = nprime[i-1];
        if (is_prime(i*i+i+41))
            ++nprime[i];
    }
}

int main() {
    compute_prime();
    compute_formula();
#if 1
    for (int i = 0; i <= 39; ++i)
        assert(is_prime(i*i+i+41));
    int from, to;
    while (scanf("%d%d", &from, &to) == 2) {
        int ans = nprime[to];
        if (from != 0)
            ans = nprime[to]-nprime[from-1];
//        printf("%.2lf\n", (double)(nprime[higher]-nprime[lower]) * 100/(to-from+1) + 1E-6);
        printf("%.2lf\n", (double)ans* 100/(to-from+1) + 1E-6);
    }
#endif
    return 0;
}
