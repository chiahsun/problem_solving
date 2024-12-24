// 0  000
// 1  001
// 2  010
// 3  011
// 4  100
// 5  101
// 6  110
// 7  111
// 8 1000

//   1010
//   1011
//   1100
class Solution {
  int rangeBitwiseAnd(int left, int right) {
    int mask = 2<<31, res = 0;
    while (mask > 0) {
        bool a = (mask & left) > 0, b = (mask & right) > 0;
        if (a || b) {
            if (a && b) res |= mask;
            else        break;
        }
        mask >>= 1;
    }
    return res;
  }
}
