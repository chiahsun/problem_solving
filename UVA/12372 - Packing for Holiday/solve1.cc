#include <cstdio>
int main() {
    int nCase, posCase = 1;
    scanf("%d", &nCase);
    while (nCase--) {
        int w, h, l;
        scanf("%d%d%d", &w, &h, &l);
        printf("Case %d: %s\n", posCase++, (w <= 20 and h <= 20 and l <= 20) ? "good" : "bad");
    }
    return 0;
}
