// a < b < c
// 1
// 2 2-1=1
// 3 3-2=1 2:3
// 4 4-3=1 3:3
// 5 5-4=1 4:3 5-3=2 3:3+1=4
// 6 6-5=1 5:3 6-4=2 4:3
// 7 7-6=1 6:3 7-5=2 5:3 7-4=3 4:3+1=4
// 8 8-7=1 7:3 8-6=2 6:3 8-5=3 5: 4+1=5

class Solution {
  int lenLongestFibSubseq(List<int> arr) {
    final N = arr.length, P = <int, int>{};
    final dp = List<List<int>>.generate(N, (i) => List<int>.filled(i, 0, growable: false), growable: false);
    int res = 0;
    for (int i = 0; i < N; ++i) {
        final c = arr[i];
        P[c] = i;
        for (int k = i-1; k >= 0; --k) {
            final b = arr[k], a = c - b;
            if (a >= b) break;
            final m = P[a];
            if (m != null) {
                dp[i][k] = (dp[k][m] > 0) ? dp[k][m]+1 : 3;
                res = max(res, dp[i][k]);
            }
        }
    }
    return res;
  }
}
