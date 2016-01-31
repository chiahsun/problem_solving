#include <cstdio>

int gcd(int x, int y) {
    while ((x %= y) and (y %= x)) ;
    return (x + y);
}

int main() {
    int N;
    while (scanf("%d", &N) and N) {
        int G = 0;
        for (int i = 1; i < N; ++i)
            for (int k = i+1; k <= N; ++k)
                G += gcd(i, k);
        printf("%d\n", G);
    }
    return 0;
}
