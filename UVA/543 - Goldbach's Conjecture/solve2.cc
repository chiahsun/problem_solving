#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
const int M = 1000000/2;
bool p[M]; 
// 0 1 2 3 4 5
// 0 1 3 5 7 9 11

void get_odd_primes() {
    memset(p, 1, sizeof(p));
    for (int i = 2; i < M; ++i) {
        if (p[i]) {
            int x = 2 * i - 1;
            for (int k = i+x; k < M; k += x) 
                p[k] = false;
        }
    }
#if 0
    for (int i = 2; i < 100; ++i) {
        if (p[i]) { printf("%d ", 2*i-1); }
    }
#endif
}

int main() {
    get_odd_primes();
    int x;
    while (scanf("%d", &x) == 1 and x != 0) {
        for (int b = (x-3); b >= 3; b -= 2) {
            int a = x - b;
            if (p[(a+1)/2] and p[(b+1)/2]) { 
                printf("%d = %d + %d\n", x, a, b);
                break;
            }
        }
    }

    return 0;
}
