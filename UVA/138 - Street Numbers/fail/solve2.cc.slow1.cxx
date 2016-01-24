#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
// Reference
//   http://stackoverflow.com/questions/1623375/writing-your-own-square-root-function
//   http://betterexplained.com/articles/understanding-quakes-fast-inverse-square-root/
//   https://en.wikipedia.org/wiki/Newton%27s_method
#if 0
double fsqrt(float x) {
    float xh = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*)&i;
    x = x * (1.5f - xh * x * x);
    return 1/x;
}
#endif

double fsqrt(double x) {
    double cur = x;
    while (fabs(cur * cur - x) > 1E-6) {
        double prev = cur;
        cur = cur/2 + x/cur/2;
        if (fabs(cur - prev) < 0.5)
            break;
    }
    return cur;
}

int main() {
#if 1
    for (unsigned long long i = 3, cnt = 0; cnt < 10 and i<= 10E9; ++i) {
        unsigned long long cur = i * (i+1);
        unsigned long long k = fsqrt((double)(cur/2))+1E-8;
        if (2 * k * k == cur) {
            printf("%10llu%10llu\n", k, i);
            ++cnt;
        }
    }
#endif
#if 0
    for (unsigned long long i = 1; i < 10E6; ++i) {
        unsigned long long a = fsqrt(i*i);
        if (i != a) {
            printf("%llu %llu (%llu)\n",i , a, i*i);
        }
    }
#endif
    
    return 0;
}
