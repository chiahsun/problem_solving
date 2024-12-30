// 3 3 5 0 0 3 1 4
// 3 3 3 0 0 0 0 0
// 0 0 2 2 2 3 3 4
//
// 3 3 5 0 0 3 1 4
// 5 5 5 4 4 4 4 4
// 4 4 4 4 4 3 3 0

// 7 6 4 3 1
// 7 6 4 3 1
// 0 0 0 0 0
//
// 7 6 4 3 1
// 7 6 4 3 1
// 0 0 0 0 0
class Solution {
  int maxProfit(List<int> prices) {
    final N = prices.length;
    final dp1 = List<int>.filled(N, 0), dp2 = List<int>.filled(N, 0);
    int minVal = prices.first;
    for (int i = 1; i < N; ++i) {
        minVal = min(minVal, prices[i]);
        dp1[i] = max(dp1[i-1], prices[i] - minVal);
    }
    int maxVal = prices.last;
    int res = dp1.last;
    for (int i = N-2; i >= 0; --i) {
        maxVal = max(maxVal, prices[i]);
        dp2[i] = max(dp2[i+1], maxVal - prices[i]);
        res = max(res, dp1[i] + dp2[i]);
    }
    return res;
  }
}
