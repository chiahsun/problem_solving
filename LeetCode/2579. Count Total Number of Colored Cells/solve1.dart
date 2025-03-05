// 1 : 1
// 2:  1+2*4-4=5
// 3:  5+3*4-4=13
class Solution {
  int coloredCells(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i)
        res += (i-1) * 4;
    return res;
  }
}
