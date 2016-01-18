#include <cstdio>
#include <cstring>

int get_mod(int a, int N) {
    long long mult = a;
    long long res = 1;
    int n = N;
    while (n > 0) {
//        printf("res: %lld, n : %d, mult : %d\n", res, n, mult);
        if (n & 1) res *= mult;
        mult *= mult;
        res %= N;
        mult %= N;
        n >>= 1;
    }
    return res;
}

const int M = 65000+5;
int a[M];

void generate_prime() {
    memset(a, true, sizeof(a));
    a[0] = a[1] = false;
    for (int i = 2+2; i < M; i += 2)
        a[i] = false;
    for (int i = 3; i < M; i += 2)
        if (a[i])
            for (int k = i+i+i; k < M; k += 2*i)
                a[k] = false;
}

int main() {
    generate_prime();
    int N;
    while (scanf("%d", &N) == 1 and N) {
        bool passFermatTest = true;
        if (not a[N]) {
            for (int i = 2; i < N; ++i) {
                int x = get_mod(i, N);
                int y = i % N;
 //               printf("get_mod(%d, %d) = %d, %d %% %d = %d\n", i, N, x, i, N, y);
                if (x != y) {
                    passFermatTest = false;
                    break;
                }
            }
        }
        if (not a[N] and passFermatTest)
            printf("The number %d is a Carmichael number.\n", N);
        else
            printf("%d is normal.\n", N);
    }
    return 0;
}
