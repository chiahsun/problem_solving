#include <cstdio>
#include <cstdlib>
#include <cmath>

int main() {
    int N, now;
    while (scanf("%d", &N) == 1 and N) {
        signed long long sum = 0;
        unsigned long long cost = 0;
        while (--N) { // intended prefix
            scanf("%u", &now);
            sum += now;
            cost += labs(sum);
        }
        scanf("%u", &now);
        printf("%llu\n", cost);
    }
    return 0;
}
