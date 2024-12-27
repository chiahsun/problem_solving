class Solution {
  int totalNQueens(int n) {
    List<int> st = [];
    int res = 0;
    void backtracking() {
        if (st.length == n) { ++res; return; }
        for (int i = 0; i < n; ++i) {
            if (st.contains(i)) continue;
            if (![for(int k = 0; k < st.length; ++k) k].every((k) => (st.length-k).abs() != (st[k] - i).abs()))
                continue;
            st.add(i);
            backtracking();
            st.removeLast();
        }
    }
    backtracking();
    return res;
  }
}
