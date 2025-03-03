class Solution {
  List<int> pivotArray(List<int> nums, int pivot) {
    int nLt = 0, nEq = 0;
    for (final n in nums) {
        if (n < pivot)       ++nLt;
        else if (n == pivot) ++nEq;
    }
    final res = List<int>.filled(nums.length, 0);
    for (int i = 0, p1 = 0, p2 = nLt, p3 = nLt + nEq; i < nums.length; ++i) {
        final n = nums[i];
        if (n < pivot)       res[p1++] = n;
        else if (n == pivot) res[p2++] = n;
        else                 res[p3++] = n;
    }
    return res;
  }
}
