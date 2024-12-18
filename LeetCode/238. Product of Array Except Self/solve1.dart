class Solution {
  List<int> productExceptSelf(List<int> nums) {
    int result = 1, nZero = 0, resultNoZero = 1;
    for (final n in nums) {
        result *= n;
        if (n == 0) ++nZero;
        else        resultNoZero *= n;
    }
    for (int i = 0; i < nums.length; ++i) {
        final n = nums[i];
        if (n == 0) {
            if (nZero == 1) nums[i] = resultNoZero;
            else            nums[i] = 0;
        } else {
            nums[i] = result ~/ n;
        }
    }
    return nums;
  }
}
