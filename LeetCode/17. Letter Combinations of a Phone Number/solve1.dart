class Solution {
  List<String> letterCombinations(String digits) {
    final dict = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    };
    int N = digits.length;
    List<String> res = [];
    void dfs(int cur, List<String> st) {
        final c = digits[cur];
        List<String> candidates = dict[c]!;
        for (int i = 0; i < candidates.length; ++i) {
            if (cur == N-1) {
                res.add(st.join() + candidates[i]);
            }
            else {
                st.add(candidates[i]);
                dfs(cur+1, st);
                st.removeLast();
            }
        }
    }
    if (!digits.isEmpty)
        dfs(0, []);
    return res;
  }
}
