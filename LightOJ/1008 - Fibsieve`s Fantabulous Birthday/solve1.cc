#include <cstdio>
#include <cmath>
#include <utility>

int main() {
    int nCase, posCase = 1;
    unsigned long long x, y, number;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%llu", &number);
        unsigned long long i = sqrt(number)+1E-6;
        unsigned long long sq = i * i;
        if (sq == number) {
            x = i; y = 1; 
        } else {
            unsigned long long d = number - sq;
            if (d <= (i+1)) {
                x = i+1; y = d;
            } else {
                d = d - (i+1);
                x = i+1-d; y = i+1;
            }
        }
        if (i % 2 == 1) 
            std::swap(x, y);
        printf("Case %d: %llu %llu\n", posCase++, x, y);
    }
    return 0;
}
