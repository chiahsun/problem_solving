#include <cstdio>

int main() {
    int nCase;
    scanf("%d", &nCase);
    for (int i = 1; i <= nCase; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("Case %d: %d\n", i, x + y);
    }
    return 0;
}
