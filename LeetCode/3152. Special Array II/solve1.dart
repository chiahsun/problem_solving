import 'package:collection/collection.dart';
// [3, 4, 1, 2, 6]
//           3
// [4,3,1,6]
//    1
// [1,1,1,2,2,3]
//  0 1   3
//
// [2,3]
// [0,1,3]
//      ^
class Solution {
  List<bool> isArraySpecial(List<int> nums, List<List<int>> queries) {
    List<int> L = [];
    for (int a = nums.first & 1, i = 1; i < nums.length; ++i) {
        final b = nums[i] & 1;
        if (a ^ b == 0) L.add(i-1);
        a = b;
    }
    List<bool> R = [];
    for (final [a, b] in queries) {
        // https://api.flutter.dev/flutter/package-collection_collection/lowerBound.html
        int pos = lowerBound(L, a);
        R.add((pos < L.length && L[pos]+1 <= b) ? false : true);
    }
    return R;
  }
}
