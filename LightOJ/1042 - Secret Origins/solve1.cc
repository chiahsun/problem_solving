#include <cstdio>

const bool debug = false;
void print_repr(const char * msg, int x) {
    printf("%s : ", msg);
    for (int mask=1<<30; mask > 0; mask >>=1)
        printf("%d", (x&mask) ? 1 : 0);
    printf("\n");
}

int main() {
    int posCase = 1, nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int a;
        scanf("%d", &a);
        if (debug)
            print_repr("before: ", a);
        for (int mask=0x1, higher_mask=0xffffffff;; mask <<= 1, higher_mask <<= 1) {
            if (mask & a) {
                while (mask & a) { mask <<= 1; higher_mask <<= 1; }
                int lower_part = a & (~higher_mask);
                if (debug) {
                    print_repr("hmask : ", higher_mask);
                    print_repr("lower1: ", lower_part);
                }
                int msb = a & (mask >> 1);
                lower_part ^= msb;
                if (debug)
                    print_repr("lower2: ", lower_part);
               
                a &= higher_mask;
                a |= mask;
                if (debug)
                    print_repr("abelow: ", a);

                while (lower_part != 0 and ((lower_part & 1) == 0)) {
                    lower_part >>= 1;
                }
                if (debug)
                    print_repr("lower3: ", lower_part);
                a |= lower_part;
                break;
            }
        }
        if (debug)
            print_repr("after : ", a);
        printf("Case %d: %d\n", posCase++, a);
    }
    return 0;
}
