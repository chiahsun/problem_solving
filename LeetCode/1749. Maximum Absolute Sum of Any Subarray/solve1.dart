// 1,-3,2 ,3 -4
// 1  0 2  5  1
// 0 -3 -1 0 -4

// 2,-5, 1  -4  3  -2
// 2  0  1   0  3   1
// 0 -5 -4  -8  -5 -7
class Solution {
  int maxAbsoluteSum(List<int> nums) {
    int a = 0, b = 0, res = 0;
    for (final n in nums) {
        a = max(a+n, 0);
        b = min(b+n, 0);
        res = max(res, max(a, -b));
    }
    return res;
  }
}
