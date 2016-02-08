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

int n_digit_prime[1000000+5];

int main() {

    int nCase;
    scanf("%d", &nCase);

    if (debug) {
        for (int i = 2; i < 100; ++i)
            if (is_digit_prime(i))
                printf("%d is digit prime\n", i);
    }

    n_digit_prime[0] = n_digit_prime[1] = 0;
    n_digit_prime[2] = 1;
    for (size_t i = 3; i < sizeof(n_digit_prime)/sizeof(n_digit_prime[0]); i += 2) {
        n_digit_prime[i] = n_digit_prime[i-1]+(is_digit_prime(i) ? 1 : 0);
        n_digit_prime[i+1] = n_digit_prime[i];
    }

    while (nCase--) {
        int from, to;
        scanf("%d%d", &from, &to);
        if (debug) {
            printf("n digit prime [%d] : %d\n", to, n_digit_prime[to]);
            printf("n digit prime [%d] : %d\n", from-1, n_digit_prime[from-1]);
        }
        printf("%d\n", n_digit_prime[to]-n_digit_prime[from-1]);
    }

    return 0;
}
