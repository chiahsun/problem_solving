//   d b b c a -
// a v
// a v
// b v v v v v
// c     v   v
// c     v v v v
// -           v
class Solution {
  bool isInterleave(String s1, String s2, String s3) {
    if (s1.length + s2.length != s3.length) return false;
    // https://stackoverflow.com/questions/57860596/creating-a-2d-array-in-flutter-dart
    List<List<bool>> m = List<List<bool>>.generate(s1.length+1, (i) => List<bool>.generate(s2.length+1, (index) => false, growable: false), growable: false);

    m[s1.length][s2.length] = true;
    for (int i = s2.length-1; i >=0; --i) {
        if (s2[i] == s3[s1.length+i]) m[s1.length][i] = true;
        else                          break;
    }
    for (int i = s1.length-1; i>=0; --i) {
        if (s1[i] == s3[s2.length+i]) {
            m[i][s2.length] = true;
        }
        else                          break;
    }
    for (int i = s1.length-1; i >= 0; --i) {
        for (int k = s2.length-1; k >= 0; --k) {
            if (!m[i][k]) {
                if (m[i][k+1] && s2[k] == s3[i+k])
                    m[i][k] = true;
            }
            if (!m[i][k]) {
                if (m[i+1][k] && s1[i] == s3[i+k])
                    m[i][k] = true;
            }
        }
    }
    return m[0][0];
  }
}
