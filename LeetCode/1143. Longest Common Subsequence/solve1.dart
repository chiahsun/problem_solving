import 'package:collection/collection.dart';
//   a c e
// a 1 1 1
// b 1 1 1
// c 1 2 2
// d 1 2 2
// e 1 2 3
class Solution {
  int longestCommonSubsequence(String text1, String text2) {
    final M = text1.length, N = text2.length;
    var dp = [List<int>.filled(N, 0), List<int>.filled(N, 0)];
    var pos = 0;
    for (int i = 0; i < M; ++i, pos=1-pos) {
        dp[1-pos][0] =  max((text1[i] == text2[0]) ? 1 : 0, dp[pos][0]);
        for (int k = 1; k < N; ++k) {
            dp[1-pos][k] = max(dp[1-pos][k-1], dp[pos][k-1] + ((text1[i] == text2[k]) ? 1 : 0));
            dp[1-pos][k] = max(dp[1-pos][k], dp[pos][k]);
        }
    }
    return dp[pos].last;
  }
}
