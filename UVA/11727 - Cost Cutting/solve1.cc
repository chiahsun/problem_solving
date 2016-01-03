#include <cstdio>
#include <utility>

int a[3];

int main() {
    int nCase;
    scanf("%d", &nCase);
    int posCase = 1;
    while (nCase--) {
        scanf("%d%d%d", a, a+1, a+2);
        if (a[0] < a[1]) std::swap(a[0], a[1]);
        if (a[1] < a[2]) std::swap(a[1], a[2]);
        if (a[0] < a[1]) std::swap(a[0], a[1]);
        printf("Case %d: %d\n", posCase++, a[1]);
    }

    return 0;
}
