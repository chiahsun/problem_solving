class Solution {
  int mySqrt(int x) {
    int lo = 0, hi = 65536;
    while (lo+1 < hi) {
        int M = lo + (hi-lo) ~/ 2;
        if (M*M <= x && x < (M+1)*(M+1)) return M;
        if (x < M*M) hi = M;
        else         lo = M;
    }

    return lo;
  }
}
