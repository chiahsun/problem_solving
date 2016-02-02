#include <cstdio>

const bool debug = false;

const int M = 2000+5;
char A[M];
char B[M];

int main() {
    int nCow;
    scanf("%d", &nCow);
    int pos_begin = 0, pos_end = nCow-1;
    for (int i = 0; i < nCow; ++i) scanf("%s", A+i);
    for (int i = 0; i < nCow; ++i) {
        if (A[pos_begin] < A[pos_end]) {
            if (debug)
                printf("set A[%d] %c\n", pos_begin, A[pos_begin]);
            B[i] = A[pos_begin++];
        } else if (A[pos_begin] > A[pos_end]) {
            if (debug)
                printf("set A[%d] %c\n", pos_end, A[pos_end]);
            B[i] = A[pos_end--];
        } else {
            if (pos_begin == pos_end) {
                if (debug)
                    printf("set A[%d] %c\n", pos_begin, A[pos_begin]);
                B[i] = A[pos_begin];
            } else {
                int pb = pos_begin, pe = pos_end;
                if (debug)
                    printf("pb : %d pe : %d\n", pb, pe);
                while (((pb+1) < (pe-1)) and A[pb] == A[pe]) {
                    if (debug)
                        printf("A[%d] %c == A[%d] %c\n", pb, A[pb], pe, A[pe]);
                    ++pb, --pe; 
                }
                if (A[pb] <= A[pe]) {
                    if (debug) {
                        printf("A[%d] %c <= A[%d] %c\n", pb, A[pb], pe, A[pe]);
                        printf("set A[%d] %c\n", pos_begin, A[pos_begin]);
                    }
                    B[i] = A[pos_begin++];
                } else {
                    if (debug) {
                        printf("A[%d] %c > A[%d] %c\n", pb, A[pb], pe, A[pe]);
                        printf("set A[%d] %c\n", pos_end, A[pos_end]);
                    }
                    B[i] = A[pos_end--];
                }
            }
        }
    }
    for (int i = 0; i < nCow; ++i) {
        if (i % 80 == 0 and i != 0) printf("\n");
        printf("%c", B[i]);
    }
    printf("\n");
    return 0;
}
