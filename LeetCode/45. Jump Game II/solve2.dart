// 2 3 1 1 4
//     ^
//    max(1+3, 2+1)
class Solution {
  int jump(List<int> nums) {
    final N = nums.length;
    int lo = 0, hi = 1, steps = 0;
    while (hi < N) {
        final currentHi = hi;
        for (int i = lo; i < currentHi && i < N && hi < N; ++i) {
            hi = max(hi, i + nums[i] + 1);
        }
        lo = currentHi; ++steps;
    }
    return steps;
  }
}
