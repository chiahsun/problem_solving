class Solution {
  void rotate(List<int> nums, int k) {
    final N = nums.length;
    k %= N;
    if (k == 0) return;
    List.copyRange(nums, 0, nums.sublist(N-k) + nums.sublist(0, N-k));
  }
}
