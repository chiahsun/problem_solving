class Solution {
  int lengthOfLongestSubstring(String s) {
    final d = List<bool>.filled(128, false);
    var start = 0, res = 0;
    final codes = s.codeUnits;
    for (int i = 0; i < codes.length; ++i) {
        final c = codes[i];
        if (d[c]) {
            while (codes[start] != c) { d[codes[start]] = false; ++start; }
            ++start;
        } else {
            d[c] = true;
        }
        res = max(res, i-start+1);
    }
    return res;
  }
}
