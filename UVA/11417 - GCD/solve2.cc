#include <cstdio>

int gcd(int x, int y) {
    while ((x %= y) and (y %= x)) ;
    return (x + y);
}

const int M = 500;
int sum[M+1];
int main() {
    int N;
    sum[2] = gcd(1, 2);
    for (int i = 3; i <= M; ++i) {
        sum[i] = sum[i-1];
        for (int k = 1; k < i; ++k)
            sum[i] += gcd(k, i);
    }
    while (scanf("%d", &N) and N) {
        printf("%d\n", sum[N]);
    }
    return 0;
}
