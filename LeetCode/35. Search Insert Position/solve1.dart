class Solution {
  int searchInsert(List<int> nums, int target) {
    int lo = 0, hi = nums.length-1;
    while (lo <= hi) {
        int M = lo + (hi - lo) ~/ 2;
        if (nums[M] == target) return M;
        if (target > nums[M]) { lo = M+1; }
        else                  { hi = M-1; }
    }
    return (lo > hi) ? lo : hi;
  }
}
