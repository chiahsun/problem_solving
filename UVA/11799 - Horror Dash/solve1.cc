#include <cstdio>
#include <algorithm>

int main() {
    int nCase;
    scanf("%d", &nCase);

    int nElement;
    int posCase = 1;
    while (nCase--) {
        scanf("%d", &nElement);
        int x, y;
        scanf("%d", &x);
        --nElement;
        while (nElement--) {
            scanf("%d", &y);
            x = std::max(x, y);
        }
        printf("Case %d: %d\n", posCase++, x);
    }
    return 0;
}
