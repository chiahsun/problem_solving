class Solution {
  List<int> productExceptSelf(List<int> nums) {
    final N = nums.length;
    final L = List<int>.filled(N, 1), R = List<int>.filled(N, 1);
    L[0] = nums[0];
    R[N-1] = nums[N-1];
    for (int i = 1; i < N; ++i) {
        L[i] = L[i-1] * nums[i];
        R[N-i-1] = R[N-i] * nums[N-i-1] ;
    }
    for (int i = 0; i < N; ++i) {
        if (i == 0) nums[i] = R[1];
        else if (i == N-1) nums[i] = L[N-2];
        else nums[i] = L[i-1] * R[i+1];
    }
    return nums;
  }
}
