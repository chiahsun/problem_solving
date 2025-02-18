class Solution {
  String smallestNumber(String pattern) {
    var used = List<bool>.filled(10, false), st = <int>[];
    final N = pattern.length;
    String? ans = null;

    void backtracking(bool? inc) {
        final lo = (inc != null && inc) ? st.last+1 : 1;
        final hi = (inc != null && !inc) ? st.last-1 : 9;
        final pos = st.length;
        for (int i = lo; i <= hi && ans == null; ++i) {
            if (used[i]) continue;
            used[i] = true; st.add(i);
            if (st.length == N+1) {
                ans = st.map((i) => i.toString()).join('');
                return;
            }
            backtracking(pattern[pos] == 'I');
            used[i] = false; st.removeLast();
        }
    }

    backtracking(null);
    return ans!;
  }
}
