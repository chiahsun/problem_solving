class Solution {
  bool areAlmostEqual(String s1, String s2) {
    if (s1.length != s2.length) return false;

    int? firstPos = null, secondPos = null;
    for (int i = 0; i < s1.length; ++i) {
        if (s1[i] != s2[i]) {
            if (firstPos == null)       { firstPos = i; }
            else if (secondPos == null) { secondPos = i; }
            else                        { return false; }
        }
    }

    return (firstPos == null) || (firstPos != null && secondPos != null && s1[firstPos] == s2[secondPos] && s1[secondPos] == s2[firstPos]);
  }
}
