class Solution {
  String minWindow(String s, String t) {
    final m = List<int>.filled(127, 0);
    final hasKey = List<bool>.filled(127, false);
    for (final c in t.codeUnits) { ++m[c]; hasKey[c] = true; }

    String res = "";
    List<int> codes = s.codeUnits;
    for (int i = 0, start = 0; i < codes.length; ++i) {
        final c = codes[i];
        if (hasKey[c]) --m[c];

        while (start < i && (!hasKey[codes[start]] || m[codes[start]] < 0)) {
            if (!hasKey[codes[start]]) {}
            else  ++m[codes[start]];
            ++start;
        }
        if (m.every((v) => v <= 0)) {
            if (res == "" || i+1-start < res.length) {
                res = s.substring(start, i+1);
            }
        }
    }
    return res;
  }
}
