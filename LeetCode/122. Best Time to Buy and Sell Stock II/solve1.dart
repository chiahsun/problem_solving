class Solution {
  int maxProfit(List<int> prices) {
    int profit = 0;
    int? last = null;
    for (final p in prices) {
        if (last == null) { last = p; }
        else {
            if (p > last) { profit += (p - last); last = p; }
            else          { last = p; }
        }
    }
    return profit;
  }
}
