import 'dart:collection';

class Solution {
  List<List<int>> mergeArrays(List<List<int>> nums1, List<List<int>> nums2) {
    final m = SplayTreeMap<int, int>();
    for (final nums in [nums1, nums2])
        for (final [i, x] in nums)
            m.update(i, (v) => v + x, ifAbsent: () => x);
    // return [for (MapEntry<int, int> e in m.entries) [e.key, e.value]];
    return [for (final e in m.entries) [e.key, e.value]];
  }
}
