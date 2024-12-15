class Solution {
  int maxProfit(List<int> prices) {
    // https://api.flutter.dev/flutter/dart-core/List-class.html
    int profit = 0, lo = prices.first;
    for (final p in prices) {
        lo = min(lo, p);
        profit = max(profit, p - lo);
    }
    return profit;
  }
}
