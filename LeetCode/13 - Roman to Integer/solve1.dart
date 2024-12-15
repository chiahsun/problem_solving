class Solution {
  int romanToInt(String s) {
    // https://api.dart.dev/dart-collection/HashMap-class.html
    final m = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000};
    String last_c = s[0];
    int val = m[last_c]!;
    var ans = 0;
    for (int i = 1; i < s.length; ++i) {
        final c = s[i];
        if (c == last_c) val += m[c]!;
        else {
            if (m[c]! > m[last_c]!) { ans = ans - val + m[c]!; val = 0; }
            else { ans += val; val = m[c]!; }
            last_c = c;
        }
    }
    return ans + val;
  }
}
