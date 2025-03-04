// 1 3  9 27  81 243
// 1 4 13 40 121 364
class Solution {
  bool checkPowersOfThree(int n) {
    int cur = 1;
    while (cur * 3 <= n) cur *= 3;
    while (n > 0 && cur > 0) {
        if (n >= cur) n -= cur;
        cur = (cur == 1) ? 0 : cur ~/ 3;
    }
    return n == 0;
  }
}
