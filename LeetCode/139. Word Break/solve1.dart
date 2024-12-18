class Solution {
  bool wordBreak(String s, List<String> wordDict) {
    final N = s.length;
    final seg = List<bool>.filled(N, false);
    seg[0] = true;
    for (int i = 0; i < N; ++i) {
        if (seg[i]) {
            for (final word in wordDict) {
                final M = i+word.length;
                if (M < N && !seg[M]) {
                    if (s.substring(i, M) == word)
                        seg[M] = true;
                } else if (M == N) {
                    if (s.substring(i, M) == word)
                        return true;
                }
            }
        }
    }
    return false;
  }
}
