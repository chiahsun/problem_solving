// 1 3  9 27  81 243
// 1 4 13 40 121 364
class Solution {
  bool checkPowersOfThree(int n) {
    List<int> vals = [1], psum = [1];
    for (int i = 3; i <= n; i *= 3) {
        vals.add(i);
        psum.add(psum.last + i);
    }

    bool backtracking(int pos, int left) {
        if (left == vals[pos] || left == psum[pos])
            return true;
        if (left > psum[pos] || pos == 0)
            return false;
        if (left > vals[pos] && backtracking(pos-1, left - vals[pos]))
            return true;
        return backtracking(pos-1, left);
    }

    return backtracking(vals.length-1, n);
  }
}
