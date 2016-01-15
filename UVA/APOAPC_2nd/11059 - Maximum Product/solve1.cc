#include <cstdio>
#include <algorithm>

typedef signed long long ll;
int a[20];

int main() {
    int posCase = 1;
    int nElement;
    while (scanf("%d", &nElement) == 1) {
        for (int i = 0; i < nElement; ++i)
            scanf("%d", a + i);

        ll vmax = 0;
        for (int i = 0; i < nElement; ++i) {
            if (a[i] != 0) {
                int begin = i, end = begin+1;
                ll product = a[begin];
                for (; end < nElement and a[end] != 0; ++end) {
                    product *= a[end];
                }
//                printf("product : %d\n", product);
                if (product > 0) {
                    vmax = std::max(vmax, product);
                } else {
                    ll x = product;
                    for (int i = end-1; i > begin; --i) {
                        x /= a[i];
                        if (x > 0)
                            break;
                    }
//                    printf("x1: %d\n", x);
                    vmax = std::max(vmax, x);
                    x = product;
                    for (int i = begin; i < end-1; ++i) {
                        x /= a[i];
                        if (x > 0)
                            break;

                    }
                    vmax = std::max(vmax, x);
//                    printf("x2: %d\n", x);
                }
                i = end;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", posCase++, vmax);
    }
}
