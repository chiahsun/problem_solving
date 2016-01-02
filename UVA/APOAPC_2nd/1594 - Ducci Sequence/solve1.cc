#include <cstdio>
#include <cstring>
#include <cstdlib>

const int M = 15+2;
int a[M];
int b[M];
int zeros[M];


void next(int x[M], int len) {
    int val_cur = x[0];
    int val_last_assign = abs(val_cur - x[len-1]);
    for (int i = 0; i < len-1; ++i) {
        int val_nxt = x[i+1];
        x[i] = abs(val_cur - val_nxt);
        val_cur = val_nxt;
    }
    x[len-1] = val_last_assign;
}

bool is_same(int x[M], int y[M], int len) { 
    return !memcmp(x, y, sizeof(int) * len); 
}
bool is_zeros(int x[M], int len) { 
    return is_same(x, zeros, len);  
}

void printx(int x[M], int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", x[i]);
    printf("\n");
}

int main() {

    memset(zeros, 0, sizeof(zeros));

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int L;
        scanf("%d", &L);
        for (int i = 0; i < L; ++i) { 
            scanf("%d", &a[i]); 
            b[i] = a[i];
        }

        bool hasCycle = false;
        do {
            next(a, L);
            next(b, L);
            next(b, L);
        } while (not is_same(a, b, L));

        printf("%s\n", is_zeros(a, L) ? "ZERO" : "LOOP");
    }

    return 0;
}
