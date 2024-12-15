class Solution {
  bool isIsomorphic(String s, String t) {
    if (s.length != t.length) return false;

    final m = Map<int, int>();
    final mapped = Set<int>();
    final codesS = s.codeUnits, codesT = t.codeUnits;
    for (int i = 0; i < codesS.length; ++i) {
        if (m.containsKey(codesS[i])) {
            if (codesT[i] != m[codesS[i]])
                return false;
        } else {
            if (mapped.contains(codesT[i]))
                return false;
            m[codesS[i]] = codesT[i];
            mapped.add(codesT[i]);
        }
    }
    return true;
  }
}
