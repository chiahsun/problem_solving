class Solution {
  List<List<int>> combinationSum(List<int> candidates, int target) {
    candidates.sort();
    final N = candidates.length;
    List<List<int>> res = [];
    List<int> st = [];
    void backtracking(int pos, int left) {
        if (left == 0) { res.add(List.from(st)); return; }
        for (int i = pos; i < N && (left - candidates[i] >= 0); ++i) {
            final cur = candidates[i];
            st.add(cur);
            backtracking(i, left-cur);
            st.removeLast();
        }
    }

    backtracking(0, target);
    return res;
  }
}
