class Solution {
  int romanToInt(String s) {
    int m(String c) {
        // https://dart.dev/language/branches
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    String last_c = s[0];
    int val = m(last_c);
    var ans = 0;
    for (int i = 1; i < s.length; ++i) {
        final c = s[i];
        if (c == last_c) val += m(c);
        else {
            if (m(c) > m(last_c)) { ans = ans - val + m(c); val = 0; }
            else { ans += val; val = m(c); }
            last_c = c;
        }
    }
    return ans + val;
  }
}
