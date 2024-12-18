class Solution {
  int trailingZeroes(int n) {
    int res = 0;
    for (int i=1, mul=5; ; ++i, mul*=5) {
        int cur = n ~/ mul;
        if (cur == 0) break;
        res += cur;
    }
    return res;
  }
}
