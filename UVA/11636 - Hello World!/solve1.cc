#include <cstdio>
#include <cmath>
#include <cstdlib>
bool double_equal(double x, double y)
  { return fabs(x - y) < 1E-9; }

int main() {
    int N;
    int posCase = 1;
    while (scanf("%d", &N) == 1 and N > 0) {
        int x = floor(log(N)/log(2));
        double res = pow(2, x);
//        printf("x : %d, res : %f\n", x, res);
        if (not double_equal(N, res))
            ++x;
        printf("Case %d: %d\n", posCase++, x);
    }
    return 0;
}
