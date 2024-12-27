class Solution {
  String placeQueen(int pos, int n) {
    final buffer = StringBuffer();
    for (int i = 0; i < n; ++i) buffer.write(i != pos ? '.' : 'Q');
    return buffer.toString();
  }

  List<List<String>> solveNQueens(int n) {
    List<int> st = [];
    List<List<String>> res = [];
    void backtracking() {
        if (st.length == n) {
            // https://stackoverflow.com/questions/61101164/dart-map-comprehension
            final List<String> cur = [for (final i in st) placeQueen(i, n)];
            res.add(cur);
            return ;
        }
        for (int i = 0; i < n; ++i) {
            if (st.contains(i)) continue;
            bool good = true;
            for (int k = 0; k < st.length; ++k) {
                if ((k - st.length).abs() == (st[k] - i).abs()){
                    good = false;
                    break;
                }
            }
            if (good) {
                st.add(i);
                backtracking();
                st.removeLast();
            }
        }
    }
    backtracking();
    return res;
  }
}
