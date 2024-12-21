class Solution {
  int findPeakElement(List<int> nums) {
    final N = nums.length;
    if (nums.length == 1 || nums.first > nums[1]) return 0;
    if (nums.last > nums[N-2]) return N-1;
    int lo = 0, hi=N-1;
    while (lo < hi) {
        int mid = lo + (hi-lo) ~/ 2;
        if (nums[mid+1] > nums[mid]) lo = mid+1;
        else                         hi = mid;
    }
    return lo;
  }
}
