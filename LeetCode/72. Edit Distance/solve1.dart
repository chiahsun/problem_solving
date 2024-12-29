//     r o s
//   0 1 2 3
// h 1 1 2 3
// o 2 2 1 2
// r 3 2 2 2
// s 4 3 3 2
// e 5 4 4 3

//   d e a
// a 1 2 2
// b 2 2 3
// c 3 3 3
class Solution {
  int min3(int a, int b, int c) => min(a, min(b, c));
  int minDistance(String word1, String word2) {
    final M = word1.length, N = word2.length;
    List<List<int>> dp = List.generate(M+1, (_) => List.filled(N+1, 0), growable: false);
    for (int i = 0; i <= M; ++i) dp[i][0] = i;
    for (int i = 0; i <= N; ++i) dp[0][i] = i;
    for (int i = 1; i <= M; ++i) {
        for (int k =1; k <= N; ++k) {
            if (word1[i-1] == word2[k-1]) {
                dp[i][k] = dp[i-1][k-1];
            } else {
                dp[i][k] = min3(dp[i-1][k-1], dp[i][k-1], dp[i-1][k])+1;
            }
        }
    }
    return dp.last.last;
  }
}
