#include <cstdio>
#include <cstring>

char A[] = { 'a', 'b', 'c', 'd', 'e', 'f'
           , 'g', 'h', 'i', 'j', 'k', 'l'
           , 'm', 'n', 'o', 'p', 'q', 'r'
           , 's', 't', 'u', 'v', 'w', 'x'
           , 'y', 'z', 'A', 'B', 'C', 'D'
           , 'E', 'F', 'G', 'H', 'I', 'J'
           , 'K', 'L', 'M', 'N', 'O', 'P'
           , 'Q', 'R', 'S', 'T', 'U', 'V'
           , 'W', 'X', 'Y', 'Z' };
const int SZ = sizeof(A)/sizeof(A[0]);
char B[SZ];

void print_floor(char* a) {
    printf("%c%c%c%c\n", a[0], a[2], a[5], a[1]);
    printf("%c%c%c%c\n\n", a[1], a[2], a[4], a[1]);
    printf("%c%c%c%c\n", a[0], a[3], a[4], a[0]);
    printf("%c%c%c%c\n", a[1], a[3], a[5], a[0]);
}

void print_array(char* a, int ncell) {
    for (int i = 0; i < ncell; ++i) {
        printf("%s%c ", (i % 6 == 0 and i != 0) ? "\n" : "", a[i]);
    }
    printf("\n");
}

int main() {
    int N;
    int firtCase = true;
    while (scanf("%d", &N) == 1) {
        if (firtCase) firtCase = false;
        else printf("\n");

        int used = (N + 5) / 6;
        memcpy(B, A, used * 6);
        int ncell = used * 6;
        for (int i = 0; i < ncell - N; ++i) {
            B[ncell-1-i] = B[0];
        }
#if 1
//        print_floor(A);
//        print_array(B, ncell);
#endif
        int height = 2 * used * (used * 2 - 1);
        bool first = true;
        printf("%d 2 4\n", height);
        for (int i = 0; i < ncell-3; i += 3) {
            for (int k = i+3; k < ncell; k += 3) {
                static char buf[6];
                for (int m = 0; m < 3; ++m) {
                    buf[m] = B[i+m];
                    buf[m+3] = B[k+m];
                }
//                printf("buf: "); print_array(buf, 6);
                if (first) first = false;
                else printf("\n");
                print_floor(buf);
            }
        }
    }
    return 0;
}
