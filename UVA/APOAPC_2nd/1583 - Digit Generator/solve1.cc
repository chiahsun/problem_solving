#include <cstdio>
#include <algorithm>

int get_num_digit(int x) {
    int ndigit = 0;
    while (x > 0) {
        ++ndigit;
        x /= 10;
    }
    return ndigit;
}

int get_digit_sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);

        int range = get_num_digit(x) * 9;
        bool ok = false;
        for (int i = std::max(1, x-range); i < x; ++i) {
            if ((get_digit_sum(i) + i) == x) {
                ok = true;
                printf("%d\n", i);
                break;
            }
        }
        if (!ok)
            printf("0\n");
    }

    return 0;
}
