class Solution {
  int maxAscendingSum(List<int> nums) {
    int prev = nums.first, sum = nums.first, res = nums.first;
    for (int i = 1; i < nums.length; ++i) {
        final cur = nums[i];
        sum = (cur <= prev) ? cur : (sum + cur);
        prev = cur;
        res = max(res, sum);
    }
    return res;
  }
}
