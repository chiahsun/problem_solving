class Solution {
  List<List<int>> combinationSum(List<int> candidates, int target) {
    candidates.sort();
    final N = candidates.length;
    List<List<int>> res = [];
    List<int> st = [];
    void backtracking(int pos, int left) {
        final candidate = candidates[pos];
        while (left >= 0) {
            if (left == 0) res.add(List.from(st));
            else {
                if (pos+1 < N && candidates[pos+1] <= left) {
                    backtracking(pos+1, left);
                }
            }
            left -= candidate;
            st.add(candidate);
        }
        while (!st.isEmpty && st.last == candidate) st.removeLast();
    }

    backtracking(0, target);
    return res;
  }
}
