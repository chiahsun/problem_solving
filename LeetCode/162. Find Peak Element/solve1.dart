class Solution {
  int findPeakElement(List<int> nums) {
    final N = nums.length;
    if (nums.length == 1 || nums.first > nums[1]) return 0;
    if (nums.last > nums[N-2]) return N-1;
    for (int i = 1; i < N-1; ++i) {
        if (nums[i-1] < nums[i] && nums[i] > nums[i+1]) return i;
    }
    return N-1;
  }
}
