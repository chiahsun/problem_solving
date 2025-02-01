class Solution {
  bool isArraySpecial(List<int> nums) {
    int a = nums.first & 1;
    for (int i = 1; i < nums.length; ++i) {
        final b = nums[i] & 1;
        if (a ^ b == 0) return false;
        a = b;
    }
    return true;
  }
}
