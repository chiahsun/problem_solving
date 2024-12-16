class Solution {
  bool canJump(List<int> nums) {
    int res = 0;
    for (int i = 0; i < nums.length; ++i) {
        if (i > res) return false;
        res = max(res, i + nums[i]);
        if (res >= nums.length-1)
             break;
    }
    return true;
  }
}
