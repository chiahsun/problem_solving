// daabcbaabcbc
// -001
// dabaabcbc
// -01001
// dababc
// -0112
// dab
// -01

// ababc    a  b a b a
// ababa    -1-1 0 1 2
// 01233
class Solution {
  String removeOccurrences(String s, String part) {
    final M = s.length, N = part.length;
    if (M < N) return s;

    List<int> fallback = List.filled(N, -1);
    for (int i = 1; i < N; ++i) {
        String c = part[i];
        int prev = fallback[i-1];
        while (prev >= 0 && part[prev+1] != c) {
            prev = fallback[prev];
        }
        if (c == part[prev+1]) {
            fallback[i] = prev+1;
        }
    }

    List<String> st = [];
    List<int> dp = [];
    for (int i = 0; i < s.length; ++i) {
        int last = (dp.isEmpty) ? -1 : dp.last;
        String c = s[i];
        while (last >= 0 && c != part[last+1]) {
            last = fallback[last];
        }
        final pos = last+1;
        if (c == part[pos]) {
            if (pos+1 == part.length) {
                st.removeRange(st.length-pos, st.length);
                dp.removeRange(dp.length-pos, dp.length);
            } else {
                st.add(c);
                dp.add(pos);
            }
        } else {
            st.add(c);
            dp.add(-1);
        }
    }
    return st.join("");
  }
}
