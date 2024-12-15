class Solution {
  int maxProfit(List<int> prices) {
    // https://api.flutter.dev/flutter/dart-core/List-class.html
    int profit = 0, lo = prices.first;
    for (final p in prices) {
        if (p < lo) lo = p;
        if (p - lo > profit) profit = p - lo;
    }
    return profit;
  }
}
