class Solution {
  bool isIsomorphic(String s, String t) {
    if (s.length != t.length) return false;

    final notFound = -1;
    final m = List<int>.filled(128, notFound);
    final mapped = List<int>.filled(128, notFound);
    final codesS = s.codeUnits, codesT = t.codeUnits;
    for (int i = 0; i < codesS.length; ++i) {
        if (m[codesS[i]] != notFound) {
            if (codesT[i] != m[codesS[i]])
                return false;
        } else {
            if (mapped[codesT[i]] != notFound)
                return false;
            m[codesS[i]] = codesT[i];
            mapped[codesT[i]] = 1;
        }
    }
    return true;
  }
}
