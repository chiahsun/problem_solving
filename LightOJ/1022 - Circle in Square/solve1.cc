#include <cstdio>
#include <cmath>

const double PI = acos(-1);

int main() {
    int nCase, posCase = 1;
    scanf("%d", &nCase);
    while (nCase--) {
        double R;
        scanf("%lf", &R);
        printf("Case %d: %.2lf\n", posCase++, R*R*(4-PI));
    }
    return 0;
}
