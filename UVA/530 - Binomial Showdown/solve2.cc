#include <cstdio>

int get_gcd(int a, int b) {
    if (b == 0) return a;
    return get_gcd(b, a%b);
}

int get_binomial(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    if (k > n-k) return get_binomial(n, n-k);

    int a = 1, b = 1;
    for (int i = k, mult = n; i >= 1; --i, --mult) {
//        printf("a : %d, b : %d\n", a, b);
        int gcd = get_gcd(mult, b * i);
        a *= (mult/gcd);
        b = (b * i/gcd);
    }
    return a;
}

int main() {
    int N, K;
    while (scanf("%d%d", &N, &K) == 2 and N) {
        printf("%d\n", get_binomial(N, K));
    }
    return 0;
}
