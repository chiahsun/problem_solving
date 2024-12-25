// ADOBECODEBANC
// +--+-+
//    +-+----+
//      +---++
//          ++-+
class Solution {
  String minWindow(String s, String t) {
    Map<String, int> m = {};
    for (int i = 0; i < t.length; ++i) {
        String c  = t[i];
        m.update(c, (v) => ++v, ifAbsent: () => 1);
    }

    String res = "";
    for (int i = 0, start = 0; i < s.length; ++i) {
        String c = s[i];
        if (m.containsKey(c)) m.update(c, (v) => --v, ifAbsent: () => 1);

        while (start < i && (!m.containsKey(s[start]) || m[s[start]]! < 0)) {
            if (!m.containsKey(s[start])) {}
            else m.update(s[start], (v) => ++v, ifAbsent: () => 1);
            ++start;
        }
        if (m.values.every((v) => v <= 0)) {
            if (res == "" || i+1-start < res.length) {
                res = s.substring(start, i+1);
            }
        }
    }
    return res;
  }
}
