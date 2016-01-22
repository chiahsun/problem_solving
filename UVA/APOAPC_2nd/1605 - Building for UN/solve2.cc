#include <cstdio>


char get_repr(int x) {
    if (x >= 0 and x < 26) return x + 'A';
    else return x - 26 + 'a';
}

int main() {
    int N;
    bool first = true;
    while (scanf("%d", &N) == 1) {
        if (first) first = false;
        else printf("\n");
        printf("2 %d %d\n", N, N);

        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < N; ++k)
                printf("%c", get_repr(i));
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < N; ++k)
                printf("%c", get_repr(k));
            printf("\n");
        }
    }
    return 0;
}
