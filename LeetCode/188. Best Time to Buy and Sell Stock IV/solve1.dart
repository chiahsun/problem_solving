// 1 3 2 4 3 6
// B
// 0
// 2 0
// 2 0 0
// 3 2 2 0
// 3 2 2 0 0
// 5 4 4 3 3 0
// k=1
// 0 2 2 3 3 5 (First column of B)
// k=2
// 0 2 2 4 4 6
// 0
// 2 2
// 2 2 2
// 3 4 4 3
// 3 4 4 3 3
// 5 6 6 6 6 5
// k=3
// 0 2 2 4 4 7
// 0
// 2 2
// 2 2 2
// 3 4 4 4
// 3 4 4 4 4
// 5 6 6 7 7 6
class Solution {
  int maxProfit(int k, List<int> prices) {
    final N = prices.length;
    final List<List<int>> B = List.generate(N+1, (i) => List.generate(i, (m) => 0, growable: false), growable: false);
    for (int len = 1; len <= N; ++len) {
        int maxVal = prices[len-1];
        for (int i = len-2; i >= 0; --i) {
            final cur = prices[i];
            maxVal = max(maxVal, cur);
            B[len][i] = max(B[len][i+1], maxVal - cur);
        }
    }
    List<List<int>> dp = List.generate(k+1, (i) => List.filled(N, 0), growable: false);
    for (int i = 0; i < N; ++i) {
        dp[1][i] = B[i+1][0];
    }
    for (int i = 2; i <= k; ++i) {
        for (int m = 0; m < N; ++m) {
            final L = List<int>.filled(m+1, 0);
            for (int n = 0; n < m+1; ++n) {
                L[n] = dp[i-1][n] + B[m+1][n];
            }
            // print('m: $m L: $L');
            dp[i][m] = L.reduce((accu, elem) => max(accu, elem));
        }
    }
    // print(B);
    // print(dp[1]);
    // print(dp);
    return dp.last.last;
  }
}
