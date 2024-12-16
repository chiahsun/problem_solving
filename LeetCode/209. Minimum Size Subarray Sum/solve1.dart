class Solution {
  int minSubArrayLen(int target, List<int> nums) {
    int total = 0, res = 0;
    for (int i = 0; i < nums.length; ++i) {
        total += nums[i];
        if (total < target) continue;
        if (res == 0) res = i+1;
        int k = 0, cur = total;
        while (k < i && (cur - nums[k]) >= target) {
            cur -= nums[k];
            if (i - k < res) res = i-k;
            ++k;
        }
    }
    return res;
  }
}
