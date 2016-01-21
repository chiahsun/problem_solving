#include <cstdio>
#include <cstring>

const int M = 46340+1;
bool prime[M];

void compute_prime() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2+2; i < M; i += 2) prime[i] = false;
    for (int i = 3; i < M; i += 2)
        if (prime[i])
            for (int k = i+i+i; k < M; k += i<<1) {
                prime[k] = false;
            }
#if 0
    for (int i = 0; i < 100; ++i)
        if (prime[i])
            printf("%d ", i);
#endif
}

void prime_factorization(int x) {
    int cur = 2;
    while (x > 1) {
        if (cur >= M)
            break;
        while (x % cur == 0) {
            printf(" %d", cur);
            x /= cur;
            if (x != 1)
                printf(" x");
        } 
        ++cur;
    }
    if (x != 1)
        printf(" %d", x);
    printf("\n");
}

int main() {
    compute_prime();
    int N;
    while (scanf("%d", &N) == 1 and N) {
        printf("%d =%s", N, (N < 0) ? " -1 x" : "");
        prime_factorization((N < 0) ? -N : N);
    }
    return 0;
}
