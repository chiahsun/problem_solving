#include <cstdio>
#include <cstring>

const int MAX = 100000 + 5;
int a[MAX];

int get_digit_sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int main() {
    memset(a, 0, sizeof(a));
    for (int i = 1; i < MAX; ++i) {
        int sum = get_digit_sum(i) + i;
        if (sum < MAX && (a[sum] == 0 || a[sum] > i))
            a[sum] = i;
    }

    int N;
    scanf("%d", &N);

    while (N--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", a[x]);
    }

    return 0;
}
