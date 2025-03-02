// import 'dart:collection';
import 'package:collection/collection.dart';

class Solution {
  List<List<int>> mergeArrays(List<List<int>> nums1, List<List<int>> nums2) {
    final LL = [nums1, nums2];
    final maxVal = [for (final nums in LL) nums.last[0]].reduce(max);
    final List<List<int>> L = [];

    // https://api.flutter.dev/flutter/package-collection_collection/IterableExtension/firstWhereIndexedOrNull.html
    for (final indices = List<int>.filled(LL.length, 0); indices.firstWhereIndexedOrNull((index, elem) => elem < LL[index].length) != null;) {
        int minVal = maxVal, total = 0;
        for (int i = 0; i < LL.length; ++i)
            if (indices[i] < LL[i].length)
                minVal = min(minVal, LL[i][indices[i]][0]);

        for (int i = 0; i < LL.length; ++i) {
            if (indices[i] < LL[i].length && LL[i][indices[i]][0] == minVal) {
                total += LL[i][indices[i]][1];
                ++indices[i];
            }
        }
        L.add([minVal, total]);
    }

    return L;
  }
}
