class Solution {
  List<int> twoSum(List<int> nums, int target) {
    final m = Map<int, int>();
    for (int i = 0; i < nums.length; ++i) {
        int cur = nums[i], other = target - cur;
        if (m.containsKey(other)) {
            return [m[other]!, i];
        }
        m[cur] = i;
    }
    return [];
  }
}
