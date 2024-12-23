enum TokenType { op, numeric }

class Token {
    final tokenType;
    int num = 0;
    String op = '?';
    Token.num(this.num) : tokenType = TokenType.numeric { }
    Token.op(this.op) : tokenType = TokenType.op { }

    bool isNum() { return tokenType == TokenType.numeric; }

    bool isPlus() { return tokenType == TokenType.op && op == '+'; }
    bool isMinus() { return tokenType == TokenType.op && op == '-'; }

    @override
    String toString() {
        switch (tokenType) {
            case TokenType.op:
                return op;
            case TokenType.numeric:
                return '$num';
        }
        return "?";
    }
}

class Solution {
  int calculate(String s) {
    bool isDigit(int pos) => s.codeUnitAt(pos) >= 48 && s.codeUnitAt(pos) <= 57;

    Token stringToToken(String s, int start, int end) {
        if (isDigit(start)) return Token.num(int.parse(s.substring(start, end)));
        else return Token.op(s[start]);
    }

    List<Token> toTokens() {
        List<Token> tokens = [];
        int? digitsStart = null;
        for (int i = 0; i < s.length; ++i) {
            if (s[i] == " ") { }
            else if (isDigit(i)) {
                if (digitsStart == null) digitsStart = i;
            } else {
                if (digitsStart != null) {
                    tokens.add(stringToToken(s, digitsStart, i));
                    digitsStart = null;
                }
                tokens.add(stringToToken(s, i, i+1));
            }
        }
        if (digitsStart != null) tokens.add(stringToToken(s, digitsStart, s.length));
        return tokens;
    }

    final tokens = toTokens();

    List<Token> st = [];
    for (final token in tokens) {
        st.add(token);
        bool found = true;
        while (found) {
            found = false;
            if (st.length >= 3) {
                final N = st.length;
                if (st[N-3].isNum() && st[N-1].isNum() && (st[N-2].isPlus() || st[N-2].isMinus())) {
                    String op = st[N-2].op;
                    found = true;
                    int a = st[N-3].num, b = st[N-1].num;
                    st.removeRange(N-3, N);
                    if (op == '+') st.add(Token.num(a + b));
                    else           st.add(Token.num(a - b));
                } else if (st[N-1].op == ')') {
                    found = true;
                    Token num = st[N-2];
                    st.removeRange(N-3, N);
                    st.add(num);
                }
            }
            if (!found && st.length >= 2) {
                final N = st.length;
                Token digitsMaybe = st[N-1];
                Token opMaybe = st[N-2];
                if (digitsMaybe.isNum() && opMaybe.isMinus()) {
                    found = true;
                    int a = digitsMaybe.num;
                    st.removeRange(N-2, N);
                    st.add(Token.num(-a));
                }
            }
        }
    }
    return st.last.num;
  }
}
