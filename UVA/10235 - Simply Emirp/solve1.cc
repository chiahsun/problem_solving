#include <cstdio>
#include <cstring>

const int M = 1000000+5;
int a[M];

void generate_prime() {
    memset(a, true, sizeof(a));
    a[0] = a[1] = false;
    for (int i = 2+2; i < M; i+=2)
        a[i] = false;
    for (int i = 3; i < M; i += 2) {
        if (a[i]) {
            for (int k = i+i+i; k < M; k += 2*i)
                a[k] = false;
        }
    }
#if 0
    for (int i = 0; i < 100; ++i)
        if (a[i])
            printf("%d ", i);
#endif
}

int digits[20];
int reverse(int x) {
    int pos = 0;
    for (; x > 0; ++pos) {
        digits[pos] = x % 10;
        x /= 10; 
    }
    int sum = 0;
    for (int i = 0; i < pos; ++i) {
        sum = 10 * sum + digits[i];
    }
    return sum;
}

int main() {
    generate_prime();

    int N;
    while (scanf("%d", &N) == 1) {
        if (N <= 1 or (not a[N])) {
            printf("%d is not prime.\n", N);
        } else {
            int re = reverse(N);
            printf("%d is %s.\n", N, (N != re and a[re]) ? "emirp" : "prime");
        }
    }

    return 0;
}
