#include <cstdio>
#include <cmath>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) == 2 and a) {
        int na = floor(sqrt(a) + 1E-8);
        int nb = floor(sqrt(b) + 1E-8);
        printf("%d\n", nb-na+(na*na == a ? 1 : 0));
    }
    return 0;
}
