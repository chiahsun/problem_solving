#include <cstdio>

unsigned long long square(unsigned long long x) { return x * x; }
int main() {
    unsigned long long x;
    while (scanf("%llu", &x) == 1) {
        printf("%llu\n", square(x) * square(x+1) / 4);
    }
    return 0;
}
