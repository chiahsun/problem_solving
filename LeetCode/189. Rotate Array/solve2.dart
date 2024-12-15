class Solution {
  void rotate(List<int> nums, int k) {
    final N = nums.length;
    k %= N;
    if (k == 0) return;
    int M = N.gcd(k);
    for (int m = 0; m < M; ++m) {
        int pos = m, cached = nums[pos];
        for (int i = 0; i < N ~/ M; ++i) {
            int targetPos = (pos + k) % N;
            int old = nums[targetPos];
            nums[targetPos] = cached;
            pos = targetPos;
            cached = old;
        }
    }
  }
}
