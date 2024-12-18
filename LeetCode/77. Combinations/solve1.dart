class Solution {
  List<List<int>> combine(int n, int k) {
    List<List<int>> res = [];
    void comb(List<int> cur, int pos) {
        for (int i = pos; i <= n-k+1+cur.length; ++i) {
            if (cur.length+1 == k) {
                res.add(cur+[i]);
            } else {
                cur.add(i);
                comb(cur, i+1);
                cur.removeLast();
            }
        }
    }
    comb([], 1);
    return res;
  }
}
