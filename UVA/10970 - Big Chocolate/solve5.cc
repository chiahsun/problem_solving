#include <cstdio>

int main() {

    int x, y;
    while (scanf("%d%d", &x, &y) == 2) {
        printf("%d\n", x * y - 1);
    }
    return 0;
}
