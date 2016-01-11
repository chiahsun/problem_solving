#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
const int M = 1000000;
bool p[M];

void get_odd_primes() {
    memset(p, 1, sizeof(p));
    for (int i = 3; i < M; i += 2) {
        if (p[i]) {
            for (int k = i+i; k < M; k += i) 
                p[k] = false;
        }
    }
}

int main() {
    get_odd_primes();
    int x;
    while (scanf("%d", &x) == 1 and x != 0) {
        for (int b = (x-3); b >= 3; b -= 2) {
            int a = x - b;
            if (p[a] and p[b]) { 
                printf("%d = %d + %d\n", x, a, b);
                break;
            }
        }
    }

    return 0;
}
