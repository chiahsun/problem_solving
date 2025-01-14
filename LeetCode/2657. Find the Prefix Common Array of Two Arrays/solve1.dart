// 0001
// 0100

// 0101
// 0101
class Solution {
  int countBits(int a) {
    int cnt = 0;
    while (a > 0) {
        a &= (a-1);
        ++cnt;
    }
    return cnt;
  }
  List<int> findThePrefixCommonArray(List<int> A, List<int> B) {
    final N = A.length;
    final res = List<int>.filled(N, 0);
    var a = 0, b = 0;
    for (int i = 0; i < N; ++i) {
        a |= (1 << A[i]);
        b |= (1 << B[i]);
        res[i] = countBits(a & b);
    }
    return res;
  }
}
