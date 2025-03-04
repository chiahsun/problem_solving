// 1 3  9 27  81 243
// 1 4 13 40 121 364
class Solution {
  bool checkPowersOfThree(int n) {
    List<int> psum = [1];
    for (int i = 3; i <= n; i *= 3) psum.add(psum.last + i);

    int getVal(int pos) => (pos == 0) ? 1 : psum[pos] - psum[pos-1];

    bool backtracking(int pos, int left) {
        if (left == getVal(pos) || left == psum[pos])
            return true;
        if (left > psum[pos] || pos == 0)
            return false;
        if (left > getVal(pos) && backtracking(pos-1, left - getVal(pos)))
            return true;
        return backtracking(pos-1, left);
    }

    return backtracking(psum.length-1, n);
  }
}
