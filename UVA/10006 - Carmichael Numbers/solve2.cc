# include <iostream>

using namespace  std;

bool isPrime(int a) {
    if (a <= 1) return false;
    if (a <= 3) return true;
    for (int d = 2; d * d <= a; ++d) {
        if (a % d == 0) return false;
    }
    return true;
}

int fastExponential(long long a, long long n) {
    const long long mod = n;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = (res * a) % mod; }
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}

bool isEQHold(int n) {
    for (int i = 2; i < n; ++i) {
        if (fastExponential(i, n) != i) {
            return false;
        }
    }
    return true;
}

int main() {
    int x;
    while ((cin >> x) && x) {
        if (isPrime(x) || !isEQHold(x)) {
            printf("%d is normal.\n", x);
        } else {
            printf("The number %d is a Carmichael number.\n", x);
        }
    }
    return 0;
}