class Solution {
  int countBadPairs(List<int> nums) {
    Map<int, int> m = {};
    for (int i = 0; i < nums.length; ++i) {
        final a = nums[i];
        // https://api.flutter.dev/flutter/dart-core/Map/update.html
        m.update(a - i, (value) => value + 1, ifAbsent: () => 1);
    }
    final N = nums.length;
    int res = N * (N-1) ~/ 2;
    for (final v in m.values) res -= (v * (v-1) ~/ 2);

    return res;
  }
}
