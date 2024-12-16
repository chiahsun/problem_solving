class Solution {
  int minSubArrayLen(int target, List<int> nums) {
    final N = nums.length;
    int total = 0, res = N+1, start = 0;
    for (int i = 0; i < nums.length; ++i) {
        total += nums[i];
        while (total >= target) {
            res = min(res, i-start+1);
            total -= nums[start];
            start++;
        }
        if (res == 1) break;
    }
    return res > N ? 0 : res;
  }
}
