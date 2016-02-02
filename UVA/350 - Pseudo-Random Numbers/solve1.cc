#include <cstdio>

int Z, I, M, L;
int next(int now) {
    return (Z * now + I) % M;
}

int main() {
    int posCase = 1;
    while (scanf("%d%d%d%d", &Z, &I, &M, &L) == 4) {
        if (Z == 0 and I == 0 and M == 0 and L == 0)
            break;
        Z %= M;

        int x = L, y = L;
        while ((x = next(x)) != ((y = next(next(y))))) { }
        int start = x;

        for (int i = 1;; ++i) {
            x = next(x);
            if (x == start) {
                printf("Case %d: %d\n", posCase++, i);
                break;
            }
        }
    }
    return 0;
}
