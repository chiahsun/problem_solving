class Solution {
  List<String> generateParenthesis(int n) {
    List<String> res = [], st = [];

    void backtracking(int l, int left) {
        if (l == 0 && left == 0) {
            res.add(st.join(''));
            return;
        }
        if (left > 0) {
            st.add('(');
            backtracking(l+1, left-1);
            st.removeLast();
        }
        if (l > 0) {
            st.add(')');
            backtracking(l-1, left);
            st.removeLast();
        }
    }
    backtracking(0, n);
    return res;
  }
}
