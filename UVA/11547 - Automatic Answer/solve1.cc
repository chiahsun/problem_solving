#include <cstdio>
#include <cstdlib>

int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        int x;
        scanf("%d", &x);
        // printf("%d\n", abs((((x * 63)  + 92) * 5 - 98) / 10) % 10); // wrong
        // printf("%d\n", abs((((x * 63)  + 7492) * 5 - 98) / 10) % 10); // wrong
        printf("%d\n", abs((((x * 63)  + 7492) * 5 - 498) / 10) % 10);
    }
    return 0;
}
