class Solution {
  bool check(List<int> nums) {
    final N = nums.length;
    int pos = -1;
    for (int i = 0; i < N-1; ++i) {
        if (nums[i+1] < nums[i]) { pos = i+1; break; }
    }
    if (pos == -1) return true;
    if (nums.last > nums.first) return false;
    for (int i = pos; i < N-1; ++i)
        if (nums[i+1] < nums[i])
            return false;
    return true;
  }
}
