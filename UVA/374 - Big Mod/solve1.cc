#include <cstdio>

int main() {
    int B, P, M;
    while (scanf("%d%d%d", &B, &P, &M) == 3) {
        int mul = B % M;

        int r = 1; 
        while (P > 0) {
            if (P & 1) r = r * mul % M;
            P >>= 1;
            mul = mul * mul % M;
        }
       
        printf("%d\n", r);
    }
    return 0;
}
