#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>

unsigned long long ull_sqrt(unsigned long long x) {
//    printf("compute sqrt(%llu)\n", x);
    unsigned long long low = 1, high = std::min(x, (unsigned long long)4294967296);
    unsigned long long mid = 1;
    while (high >= low) {
        // mid = low + (high-low)/2;
        mid = (high+low)/2;
        unsigned long long res = mid * mid;
        if (res < mid) {
            printf("mid %llu, res %llu\n", mid, res);
            assert(res >= mid);
        }
        if (res == x) break; 
        else if (res > x) high = mid-1;
        else low = mid+1;
    }
    return mid;
}

int main() {
#if 1 
    int cnt = 0;
    for (unsigned long long i = 3; i<= 10E9; ++i) {
        unsigned long long cur = i * (i+1);
        unsigned long long k = sqrt((double)(cur/2))+1E-8;
        // unsigned long long k = ull_sqrt(cur/2);
        if (2 * k * k == cur) {
            // printf("%llu %llu (%llu)\n", k, i, cur);
            printf("%10llu%10llu\n", k, i);
            ++cnt;
        }
        if (cnt == 10)
            break;
    }    
#endif
#if 0
    for (unsigned long long i = 1; i < 10E5; ++i) {
        unsigned long long a = ull_sqrt(i*i);
        if (i != a) {
            printf("%llu %llu (%llu)\n",i , a, i*i);
        }
    }
//        printf("%llu %llu %llu\n", i, i*i, ull_sqrt(i*i));
#endif
    return 0;
}
