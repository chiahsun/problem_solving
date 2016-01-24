#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>

// 2 * k**2  = n * (n + 1) with (k, n) integer solutions
int main() {
    for (unsigned long long i = 3, cnt = 0; cnt < 10 and i <= 10E9; ++i) {
        unsigned long long cur = i * (i+1);
        unsigned long long k = sqrt((double)(cur/2))+1E-8;
        if (2 * k * k == cur) {
            printf("%10llu%10llu\n", k, i);
            ++cnt;
        }
    }    
    return 0;
}
