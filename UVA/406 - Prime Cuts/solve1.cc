#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const bool debug = false;

const int M = 1000+5;
bool a[M];
int c[M];
int main() {
    std::vector<int> primes;
    memset(a, true, sizeof(a));
    a[0] = false;
    primes.push_back(1);
    for (int i = 2; i < M; ++i) {
        if (a[i]) {
            primes.push_back(i);
            for (int k = i+i; k < M; k += i) {
                a[k] = false;
            }
        }
    }

    c[0] = 0; 
    c[1] = 1;
    for (int i = 2; i < M; ++i) {
        c[i] = c[i-1] + (a[i] ? 1 : 0);
    }

    int N, C;
    int M;
    while (scanf("%d%d", &N, &C) == 2) {
        M = 2 * C;
        if (c[N] % 2 == 1) M -= 1;
        M = std::min(c[N], M); 

        auto it = std::lower_bound(primes.begin(), primes.end(), N);
        if (*it != N)
            --it;
        int end = it-primes.begin();
        if (debug)
            printf("vec[%ld] = %d\n", it-primes.begin(), *it);
        
        int begin = std::max(0, end/2-C+1);
        if (debug)
            printf("begin : %d, M : %d\n", begin, M);
        printf("%d %d:", N, C);
        for (int i = begin; i < begin + M; ++i)
            printf(" %d", primes[i]);
        printf("\n\n");
        
    }

    return 0;
}
