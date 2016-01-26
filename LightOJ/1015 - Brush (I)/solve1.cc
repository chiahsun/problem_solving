#include <cstdio>

int main() {
    int nCase, posCase = 1, N;
    scanf("%d", &nCase);

    while (nCase--) {
        int sum = 0;
        scanf("%d", &N);
        while (N--) {
            int x;
            scanf("%d", &x);
            if (x > 0)
                sum += x;
        }
        printf("Case %d: %d\n", posCase++, sum);
    }
    return 0;
}
