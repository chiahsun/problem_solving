#include <cstdio>

int ipow(int x, int e) {
    int res = 1;
    while (e--) res *= x;
    return res; 
}

void print_number(int x, int n_digit) {
    int s = ipow(10, n_digit);
    do {
        s /= 10;
        printf("%d", x/s%10);
    } while (s != 1);
    printf("\n");
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        N /= 2;
        int bound = ipow(10, N);
        for (int i = 0; i < bound; ++i) {
            int ans = ipow(i, 2);
            if (ipow((ans/bound) + ans%bound, 2) == ans) {
                print_number(ans, N*2);
       //         printf("%d\n", ans);
            }
        }
    }
    return 0;
}
