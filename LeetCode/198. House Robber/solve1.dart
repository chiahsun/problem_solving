// 1 2 3 1
// 1 2 4 3

// 2 7  9  3 1
// 2 7 11 10 12

// 10 1  1 10  1
// 10 1 11 20 12
class Solution {
  int rob(List<int> nums) {
    if (nums.length == 1) return nums.first;
    int res = max(nums[0], nums[1]);
    for (int i = 2; i < nums.length; ++i) {
        nums[i] = nums[i] + max(nums[i-2], i-3 >= 0 ? nums[i-3] : 0);
        res = max(res, nums[i]);
    }
    // print(nums);
    return res;
  }
}
