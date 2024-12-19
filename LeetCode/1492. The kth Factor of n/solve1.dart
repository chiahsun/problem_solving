class Solution {
  int kthFactor(int n, int k) {
    List<int> divisors = [];
    List<int> exponents = [];
    int divisor = 2;
    while (n > 1) {
        if (n % divisor == 0) {
            divisors.add(divisor);
            int cnt = 0;
            while (n % divisor == 0) {
                n ~/= divisor; ++cnt;
            }
            exponents.add(cnt);
        }
        ++divisor;
    }

    List<int> factors = [];
    void get_factors(int cur, int pos) {
        if (pos == divisors.length) {
            factors.add(cur);
            return;
        }
        int d = divisors[pos], e = exponents[pos];
        for (int i = 0, mul=1; i <= e; ++i, mul *= d) {
            get_factors(cur * mul, pos+1);
        }
    }

    get_factors(1, 0);
    factors.sort();
    return (k-1 < factors.length) ? factors[k-1] : -1;
  }
}
