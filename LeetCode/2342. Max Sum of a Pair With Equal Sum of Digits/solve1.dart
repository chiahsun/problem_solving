// 18,43,36,13,7
//  9  7  9  4 7

class Solution {
  int getDigitsSum(int a) {
    int sum = 0;
    while (a > 0) {
        sum += (a % 10);
        a ~/= 10;
    }
    return sum;
  }

  int maximumSum(List<int> nums) {
    Map<int, List<int>> m = {};
    for (int i = 0; i < nums.length; ++i) {
        final a = nums[i], d = getDigitsSum(a);
        final L = m[d];
        if (L == null) {
            m[d] = [i];
        } else {
            L.add(i);
            L.sort((a, b) => -nums[a].compareTo(nums[b]));
            if (L.length > 2) L.removeLast();
        }
    }
    int res = -1;
    for (final L in m.values) {
        if (L.length == 2) {
            res = max(res, nums[L[0]] + nums[L[1]]);
        }
    }
    return res;
  }
}
