#include <cstdio>
#include <algorithm>
// Put all knights on the same color
// But if row or col is 2
// O O X X O
// O O X X O
// it can be more nights
int main() {
    int nCase, posCase = 1, nrow, ncol;
    scanf("%d", &nCase);
    while (scanf("%d%d", &nrow, &ncol) == 2) {
        if (nrow == 1 or ncol == 1)
            printf("Case %d: %d\n", posCase++, nrow+ncol-1);
        else if (std::min(nrow, ncol) == 2)
            printf("Case %d: %d\n", posCase++, (nrow*ncol/8)*4 + std::min(4, nrow*ncol%8));
        else
            printf("Case %d: %d\n", posCase++, (nrow*ncol+1)/2);
    }
    return 0;
}
