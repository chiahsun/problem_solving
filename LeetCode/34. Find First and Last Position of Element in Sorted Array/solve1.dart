class Solution {
  // First index that >= target
  int lowerBound(List<int> nums, int target) {
    int lo = 0, hi = nums.length-1;
    while (lo < hi) {
        int mid = lo + (hi - lo) ~/ 2;
        if (nums[mid] >= target) { hi = mid; }
        else                     { lo = mid+1; }
    }
    return hi;
  }

  // First index that > target
  int upperBound(List<int> nums, int target) {
    int lo = 0, hi = nums.length-1;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) ~/ 2;
        if (nums[mid] <= target) { lo = mid; }
        else                     { hi = mid - 1; }
    }
    return lo;
  }

  List<int> searchRange(List<int> nums, int target) {
    final first = lowerBound(nums, target);
    if (first == -1 || nums[first] != target) return [-1, -1];
    return [first, upperBound(nums, target)];
  }
}
