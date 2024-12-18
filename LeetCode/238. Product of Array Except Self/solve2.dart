class Solution {
  List<int> productExceptSelf(List<int> nums) {
    int result = 1, nZero = 0, resultNoZero = 1, posZero = 0;
    for (int i = 0; i < nums.length; ++i) {
        final n = nums[i];
        result *= n;
        if (n == 0) { ++nZero; posZero = i; }
        else        { resultNoZero *= n; }
    }
    var filled = List<int>.filled(nums.length, 0);
    if (nZero == 1) { filled[posZero] = resultNoZero; }
    if (nZero >= 1) return filled;
    return nums.map((n) => result ~/ n).toList();
  }
}
