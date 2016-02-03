#include <cstdio>

int main() {
    int nPlayer, posStart, nPass, nCase, posCase = 1;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d%d", &nPlayer, &posStart, &nPass);

        printf("Case %d: %d\n", posCase++, (nPlayer-1+posStart + nPass) % nPlayer + 1);
    }
    return 0;
}
