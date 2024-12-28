// 1 2 1 2 6 7 5 1
// 1 2
//     1 2
//         6 7
//       2 6 7 5
// 1 2 1 2 6 7 5 1
//             5 1
//           7 5
//         6 7
//       2 6 7 5 (20)
//     1 2 6 7   (16)
class Solution {
  List<int> maxSumOfThreeSubarrays(List<int> nums, int k) {
    final N = nums.length;
    final dp = List<int>.filled(N, 0), dpOri = List<int>.filled(N, 0), dpLast = List<int>.filled(N, 0);
    int s = 0;
    for (int i = N-1; i >=0; --i) {
        s += nums[i];
        if (i <= N-k-1) { s -= nums[i+k]; }
        if (i <= N-k) {
            dp[i] = dpOri[i] = s;
            dpLast[i] = i;
            if (i+1 >= N) continue;
            if (dpOri[i] < dp[i+1]) {
                dp[i] = dp[i+1];
                dpLast[i] = dpLast[i+1];
            }
        }
    }
    // print(dpLast);
    // print(dpOri);
    // print(dp);
    s = 0;
    final dp2 = List<int>.filled(N, 0), dp2Ori = List<int>.filled(N, 0), dp2Last = List<int>.filled(N, 0);
    for (int i = N-k-1; i >=0; --i) {
        s += nums[i];
        if (i <= N-2*k-1) { s -= nums[i+k]; }
        if (i <= N-2*k) {
            dp2[i] = dp2Ori[i] = s + dp[i+k];
            dp2Last[i] = i;
            if (dp2Ori[i]< dp2[i+1]) {
                dp2[i] = dp2[i+1];
                dp2Last[i] = dp2Last[i+1];
            }
        }
    }
    // print(dp2Last);
    // print(dp2Ori);
    // print(dp2);
    s = 0;
    final dp3 = List<int>.filled(N, 0), dp3Ori = List<int>.filled(N, 0), dp3Last = List<int>.filled(N, 0);
    for (int i = N-2*k-1; i >=0; --i) {
        s += nums[i];
        if (i <= N-3*k-1) { s -= nums[i+k]; }
        // if (i <= N-3*k) { dp3[i] = max(dp3[i+1], s + dp2[i+k]); }
        if (i <= N-3*k) {
            dp3[i] = dp3Ori[i] = s + dp2[i+k];
            dp3Last[i] = i;
            if (dp3Ori[i] < dp3[i+1]) {
                dp3[i] = dp3[i+1];
                dp3Last[i] = dp3Last[i+1];
            }
        }
    }
    // print(dp3Last);
    // print(dp3Ori);
    // print(dp3);
    final a = dp3Last[0];
    final b = dp2Last[a+k];
    final c = dpLast[b+k];
    return [a, b, c];
  }
}
