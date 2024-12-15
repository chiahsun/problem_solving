class Solution {
  bool isHappy(int n) {
    int next(int n) {
      int res = 0;
      while (n > 0) {
        int digit = n % 10;
        res += digit * digit;
        n ~/= 10;
      }
      return res;
    }

    int n1 = n, n2 = n;
    do {
        n1 = next(n1); n2 = next(next(n2));
    } while (n1 != n2);

    return n1 == 1;
  }
}
