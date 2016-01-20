#include <cstdio>
#include <cmath>
#include <algorithm>

int get_divisor(int A, int B, int height, int mod_min, int & total_height, int & nidle) {
    if (B+1 == A) 
        return B;
    if (A < B) 
        return 0;
    for (int i = mod_min; i <= sqrt(B)+1; ++i) {
        if (B % i == 0 and A % (i+1) == 0) {
            int cur_ncat = B / i;
            int cur_height = height * (i+1);
            if (get_divisor(A / (i+1), cur_ncat, cur_height, mod_min, total_height, nidle)) {
//                printf("ncat : %d , cur_height : %d\n", cur_ncat, cur_height);
                nidle += cur_ncat;
                total_height += cur_height * cur_ncat;
                return i;
            } else {
                mod_min = std::max(mod_min, i+1);
            }
        }
    }
    return 0;
}

int main() {
    int A, B;
    while (scanf("%d%d", &A, &B) == 2 and A) {
        int total_height = A, nidle = 0, mod_min = 1;
        if (A != 1) { 
            total_height = A + B, nidle = 1;
            get_divisor(A, B, 1, mod_min, total_height, nidle);
        }
        printf("%d %d\n", nidle, total_height);
    }
    return 0;
}
