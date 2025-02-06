class Solution {
  int tupleSameProduct(List<int> nums) {
    nums.sort();

    int res = 0;
    void has_target(int i, int k, int target) {
        while (i < k) {
            final c = nums[i], d = nums[k];
            if (c * d == target)     { res += 8; ++i; --k; }
            else if (c * d < target) { ++i; }
            else                     { --k; }
        }
    }

    final N = nums.length;
    for (int i = 0; i < N-3; ++i) {
        for (int k = N-1; k > i+2; --k) {
            final a = nums[i], d = nums[k], target = a*d;
            if (a * d < nums[i+1] * nums[i+2])
                break;
            has_target(i+1, k-1, target);
        }
    }
    return res;
  }
}
