class Solution {
  int findMin(List<int> nums) {
    int lo = 0, hi = nums.length-1;
    while (lo < hi) {
        if (nums.first < nums.last) { return nums.first; }
        final N = lo + (hi - lo) ~/ 2;
        if (nums[N] >= nums.first) lo = N+1;
        else                       hi = N;
    }
    return nums[lo];
  }
}
