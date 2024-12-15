class Solution {
  bool containsNearbyDuplicate(List<int> nums, int k) {
    final m = Map<int, int>();
    for (int i = 0; i < nums.length; ++i) {
        int n = nums[i];
        if (m.containsKey(n)) {
            if (i - m[n]! <= k)
                return true;
        }
        m[n] = i;
    }
    return false;
  }
}
