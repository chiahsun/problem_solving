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
    var dp1 = List<int>.filled(N, 0), dp2 = List<int>.filled(N, 0);
    for (int i = 0; i < M; ++i) {
        dp2[0] = (text1[i] == text2[0]) ? 1 : dp1[0];
        for (int k = 1; k < N; ++k) {
            if (text1[i] == text2[k]) dp2[k] = dp1[k-1] + 1;
            else                      dp2[k] = max(dp1[k], dp2[k-1]);
        }
        var tmp = dp1; dp1 = dp2; dp2 = tmp;
    }
    return dp1.last;
  }
}
