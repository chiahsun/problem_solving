class Solution {
  int maxSubarraySumCircular(List<int> nums) {
    final N = nums.length;
    var posSum = nums.first, negSum = 0;
    var maxPosSum = nums.first, maxNegSum = 0, total = nums.first;
    for (int i = 1; i < N; ++i) {
        final n = nums[i];
        total += n;
        // print('n: $n');
        posSum = (posSum > 0) ? posSum + n : n;
        negSum = (negSum < 0) ? negSum + n : n;
        maxPosSum = max(maxPosSum, posSum);
        maxNegSum = min(maxNegSum, negSum);
        // print(' > poSum: $posSum negSum: $negSum maxPosSum: $maxPosSum maxNegSum: $maxNegSum');
    }
    return max(maxPosSum, total - maxNegSum);
  }
}
