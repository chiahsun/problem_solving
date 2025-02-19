class Solution {
  String getHappyString(int n, int k) {
    List<String> st = [];
    int cnt = 0;
    String backtracking() {
        if (st.length == n) return (++cnt == k) ? st.join('') : '';

        for (final c in ['a', 'b', 'c']) {
            if (!st.isEmpty && c == st.last) continue;
            st.add(c);
            String s;
            if ((s = backtracking()) != '') return s;
            st.removeLast();
        }
        return '';
    }
    return backtracking();
  }
}
