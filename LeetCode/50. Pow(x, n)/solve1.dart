class Solution {
  double myPow(double x, int n) {
    if (x == 0) return 0;
    if (n == 0) return 1;
    double m = x;
    double res = 1;
    // https://api.flutter.dev/flutter/dart-core/num/abs.html
    for (int a = (n).abs(); a >= 1; m *= m, a >>= 1) {
        if (a & 1 > 0) res *= m;
    }

    return (n > 0) ? res : 1/res;
  }
}
