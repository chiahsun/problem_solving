#include <cstdio>
#include <cmath>
#include <algorithm>

int P, A, B, C, D, N;
double p, a, b, c, d;

double price(int k) {
    return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main() {
        
    while (scanf("%d%d%d%d%d%d", &P, &A, &B, &C, &D, &N) == 6) {
        p = P, a = A, b = B, c = C, d = D;
        double vmax = price(1), dmax = 0;
        for (int i = 2; i <= N; ++i) {
            vmax = std::max(vmax, price(i));
            dmax = std::max(dmax, vmax - price(i));
        }
        printf("%.8lf\n", dmax);
    }

    return 0;
}
