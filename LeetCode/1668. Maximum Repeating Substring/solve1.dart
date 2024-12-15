class Solution {
  int maxRepeating(String sequence, String word) {
    final dp = List<int>.filled(sequence.length, 0);
    final N = word.length;
    int res = 0;
    for (int i = 0; i < sequence.length-word.length+1; ++i) {
        if (sequence.substring(i, i+N) == word) {
            dp[i] = ((i - N >= 0) ? dp[i-N] : 0) + 1;
            if (dp[i] > res) res = dp[i];
        }
    }
    return res;
  }
}
