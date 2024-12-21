class Solution {
  int coinChange(List<int> coins, int amount) {
    final cc = List<int>.filled(amount+1, -1);
    cc[0] = 0;
    for (final c in coins)
        if (c < cc.length)
            cc[c] = 1;
    for (int i = 1; i < cc.length; ++i) {
        if (cc[i] > 0) {
            for (final c in coins) {
                if (c + i < cc.length) {
                    cc[c+i] = (cc[c+i] == -1) ? cc[i] + 1 : min(cc[c+i], cc[i] + 1);
                }
            }
        }
    }
    return cc.last;
  }
}
