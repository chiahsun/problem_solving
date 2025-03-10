// C(6, 2) - 3 = 12
// 10101
// 101 -> 3
//  010 -> 3
//   101 -> 3
//    01 -> 2
//     1 -> 1

// C(8, 2) - 3 = 28 - 3 = 25
// 1010101
// 10101 -> 5
//  01010 -> 5
//   10101 -> 5
//    4 3 2 1

// k = 3
// 00111
class Solution {
  int countKConstraintSubstrings(String s, int k) {
    final N = s.length;
    int res = 0;
    for (var i = 0, cnts = [0, 0], end = 0; i < N; ++i) {
        while (end < N) {
            int pos = (s[end] == '0') ? 0 : 1;
            if (cnts[pos] + 1 > k && cnts[1 - pos] > k) break;
            ++cnts[pos];
            ++end;
        }
        if (end == N) {
            final M = (end - i);
            res += ((M+1) * M ~/ 2);
            break;
        }
        res += (end - i);
        --cnts[(s[i] == '0') ? 0 : 1];
    }
    return res;
  }
}
