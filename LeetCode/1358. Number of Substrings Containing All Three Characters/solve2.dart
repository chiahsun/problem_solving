// abcabc
// abc -> 1
//  bca -> 2
//   cab -> 3
//    abc -> 4

// aabbcca
//
// aab
// aabb
// aabbc
//  abbc -> 2
//  abbcc -> 2
//  abbcca
//    bcca -> 4
class Solution {
  int numberOfSubstrings(String s) {
    final N = s.length;
    int getPos(String c) {
        if (c == 'a') return 0;
        else if (c == 'b') return 1;
        return 2;
    }
    final cnts = [0, 0, 0];
    int begin = 0, res = 0;
    for (int i = 0; i < N; ++i) {
        ++cnts[getPos(s[i])];
        if (cnts.every((cnt) => cnt > 0)) {
            while (begin <= i-3 && cnts[getPos(s[begin])] > 1) {
                --cnts[getPos(s[begin])];
                ++begin;
            }
            res += (begin+1);
        }
    }
    return res;
  }
}
