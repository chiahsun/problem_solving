#include <cstdio>
#include <cmath>
#include <utility>

int main() {
    int x;
    while (scanf("%d", &x) == 1) {
        int n = (-1 + sqrt(1+8*x))/2 + 1E-8;
        int sum = (n+1) * n / 2;
        printf("TERM %d IS ", x);
//        printf("sum : %d ", sum);
        if (x == sum) {
            if (n % 2 == 1)
                printf("1/%d\n", n);
            else
                printf("%d/1\n", n);
        } else {
            int now = n+2;
            int nu = now - (x-sum);
            int de = now - nu;
            if (n % 2 == 1)
                std::swap(nu, de);
            printf("%d/%d\n", nu, de);
        }
    }
    return 0;
}

