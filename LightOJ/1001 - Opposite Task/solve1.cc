#include <cstdio>
#include <algorithm>

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int sum;
        scanf("%d", &sum);
        int x = std::min(10, sum);
        int y = sum - x;
        printf("%d %d\n", x, y);
    }
    return 0;
}
