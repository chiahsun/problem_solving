#include <cstdio>

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int lcm, gcd;
        scanf("%d%d", &lcm, &gcd);
        if (gcd >= lcm and gcd % lcm == 0) {
            printf("%d %d\n", lcm, gcd);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
