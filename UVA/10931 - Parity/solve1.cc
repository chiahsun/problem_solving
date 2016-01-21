#include <cstdio>

const int M = 32 + 5;
int a[M];
int main() {
    int N;
    while (scanf("%d", &N) == 1 and N > 0) {
        int cnt = 0, x = N;
        int i = 0;
        for (; i < M and x > 0; ++i) {
            a[i] = x & 1;
            cnt += x & 1;
            x >>= 1;
        }
        printf("The parity of ");
        for (int k = i-1; k >=0; --k)
            printf("%d", a[k]);
        printf(" is %d (mod 2).\n", cnt);
    }
    return 0;
}
