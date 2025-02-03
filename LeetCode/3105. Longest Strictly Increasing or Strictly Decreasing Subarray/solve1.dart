class Solution {
  int longestMonotonicSubarray(List<int> nums) {
    int prev = nums.first, m = 1, n = 1, res = 1;
    for (int i = 1; i < nums.length; ++i) {
        final cur = nums[i];
        if (cur > prev) { ++m; res = max(res, m); }
        else            { m = 1; }
        if (cur < prev) { ++n; res = max(res, n); }
        else            { n = 1; }
        prev = cur;
    }
    return res;
  }
}
