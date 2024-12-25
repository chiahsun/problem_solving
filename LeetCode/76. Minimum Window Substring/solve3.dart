class Solution {
  int lookup(String s) {
    int c = s.codeUnitAt(0);
    if (c <= 90) return c - 65;
    else         return c - 97 + 26;
  }

  String minWindow(String s, String t) {
    final m = List<int>.filled(52, 0);
    final hasKey = List<bool>.filled(52, false);
    for (int i = 0; i < t.length; ++i) { ++m[lookup(t[i])]; hasKey[lookup(t[i])] = true; }

    String res = "";
    for (int i = 0, start = 0; i < s.length; ++i) {
        final c = s[i];
        if (hasKey[lookup(c)]) --m[lookup(c)];

        while (start < i && (!hasKey[lookup(s[start])] || m[lookup(s[start])] < 0)) {
            if (!hasKey[lookup(s[start])]) {}
            else  ++m[lookup(s[start])];
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
