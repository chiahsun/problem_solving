#include <cstdio>
#include <cstring>

int a[10];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);

        memset(a, 0, sizeof(a));

        for (int i = 1; i <= x; ++i) {
            int now = i;
            while (now > 0) {
                ++a[now % 10];
                now /= 10;
            }
        }

        for (int i = 0; i < 10-1; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[9]);
    }
    return 0;
}
