#include <cstdio>

const bool debug = false;

bool is_prime(int x) {
    if (x < 4) return (x == 2 or x == 3);
    if (x % 2 == 0 or x % 3 == 0) return false;

    for (int i = 5; i*i <= x; i += 6)
       if ((x % i == 0) or (x % (i+2) == 0)) 
           return false;
    return true;
}

bool is_digit_prime(int x) {
    int sum = 0, now = x;
    while (now > 0) {
        sum += (now % 10);
        now /= 10;
    }
    return (is_prime(sum) and is_prime(x));
}

const int M = 1000000+5;
int n_digit_prime[M/2+5];

int get_n_digit_prime(int x) {
    if (x == 0 or x == 1) return 0;
    if (x == 2) return 1;
    return n_digit_prime[(x-1)/2];
}

int main() {

    int nCase;
    scanf("%d", &nCase);

    if (debug) {
        for (int i = 2; i < 100; ++i)
            if (is_digit_prime(i))
                printf("%d is digit prime\n", i);
    }

    n_digit_prime[0] = 1; // means 2
    for (size_t i = 3; i < M; i += 2) {
        size_t pos = i/2;
        n_digit_prime[pos] = n_digit_prime[pos-1]+(is_digit_prime(i) ? 1 : 0);
    }
#if 1 
    while (nCase--) {
        int from, to;
        scanf("%d%d", &from, &to);
        if (debug) {
            printf("n digit prime [%d] : %d\n", to, get_n_digit_prime(to));
            printf("n digit prime [%d] : %d\n", from-1, get_n_digit_prime(from-1));
        }
        printf("%d\n", get_n_digit_prime(to)-get_n_digit_prime(from-1));
    }
#endif

    return 0;
}
