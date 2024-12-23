class Solution {
  int calculate(String s) {
    bool isDigit(String s) {
        return (s.length > 1 && s[0] == '-') || (s.codeUnitAt(0) >= 48 && s.codeUnitAt(0) <= 57);
    }

    List<String> toTokens() {
        List<String> tokens = [];
        int? digitsStart = null;
        for (int i = 0; i < s.length; ++i) {
            if (s[i] == " ") { }
            else if (isDigit(s[i])) {
                if (digitsStart == null) digitsStart = i;
            } else {
                if (digitsStart != null) {
                    tokens.add(s.substring(digitsStart, i));
                    digitsStart = null;
                }
                tokens.add(s[i]);
            }
        }
        if (digitsStart != null) tokens.add(s.substring(digitsStart));
        return tokens;
    }

    final tokens = toTokens();
    List<String> st = [];
    for (final token in tokens) {
        st.add(token);
        bool found = true;
        while (found) {
            found = false;
            if (st.length >= 3) {
                final N = st.length;
                if (isDigit(st[N-3]) && isDigit(st[N-1]) && (st[N-2] == '+' || st[N-2] == '-')) {
                    String op = st[N-2];
                    found = true;
                    int a = int.parse(st[N-3]), b = int.parse(st[N-1]);
                    st.removeRange(N-3, N);
                    if (op == '+') st.add((a + b).toRadixString(10));
                    else           st.add((a - b).toRadixString(10));
                } else if (st[N-1] == ')') {
                    found = true;
                    String digits = st[N-2];
                    st.removeRange(N-3, N);
                    st.add(digits);
                }
            }
            if (!found && st.length >= 2) {
                final N = st.length;
                String digitsMaybe = st[N-1];
                String opMaybe = st[N-2];
                if (isDigit(digitsMaybe) && opMaybe == '-') {
                    found = true;
                    int a = -int.parse(digitsMaybe);
                    st.removeRange(N-2, N);
                    st.add(a.toRadixString(10));
                }
            }
        }
    }
    return int.parse(st.last);
  }
}
