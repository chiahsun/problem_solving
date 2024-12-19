class Solution {
  int evalRPN(List<String> tokens) {
    List<int> st = [];
    int res = 0;
    for (final t in tokens) {
        if (['+', '-', '*', '/'].contains(t)) {
            final b = st.removeLast(), a = st.removeLast();
            switch(t) {
                case '+': st.add(a + b);
                case '-': st.add(a - b);
                case '*': st.add(a * b);
                case '/': st.add(a ~/ b);
                default:
            }
        } else {
            st.add(int.parse(t));
        }
    }
    return st.last;
  }
}
