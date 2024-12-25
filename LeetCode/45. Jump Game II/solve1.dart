// 2 3 1 1 4
// 0 1 1
// 0     2 2

// 2 3 0 1 4
// 0 1 1
//       2 2
class Solution {
  int jump(List<int> nums) {
    final N = nums.length;
    List<int> dp = List<int>.filled(N, 10000);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int k = i+1; k <= i+nums[i] && k < N; ++k) {
            dp[k] = min(dp[k], dp[i]+1);
        }
    }
    return dp[N-1];
  }
}
