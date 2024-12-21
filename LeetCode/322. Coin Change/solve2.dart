class Solution {
  int coinChange(List<int> coins, int amount) {
    final cc = List<int>.filled(amount+1, -1);
    cc[0] = 0;
    for (int i = 1; i < cc.length; ++i) {
        if (cc[i] == -1) {
            for (final c in coins) {
                if (i - c >= 0 && cc[i-c] >= 0) {
                    if (cc[i] == -1) cc[i] = cc[i-c] + 1;
                    else             cc[i] = min(cc[i], cc[i-c] + 1);
                }
            }
        }
    }
    return cc.last;
  }
}
