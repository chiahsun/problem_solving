#include <cstdio>
#include <utility>

int main() {
    unsigned int x, y, z;
    while (scanf("%d%d%d", &x, &y, &z) == 3 and x) {
        if (x > y) std::swap(x, y);
        if (y > z) std::swap(y, z);
        printf("%s\n", (x * x + y * y == z * z) ? "right" : "wrong");
    }
    return 0;
}
