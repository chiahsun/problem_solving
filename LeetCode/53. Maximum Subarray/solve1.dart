class Solution {
  int maxSubArray(List<int> nums) {
    int cur = 0, res = nums[0];
    for (final n in nums) {
        cur += n;
        res = max(res, cur);
        cur = max(0, cur);
    }
    return res;
  }
}
