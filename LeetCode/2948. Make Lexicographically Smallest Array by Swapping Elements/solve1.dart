import 'package:collection/collection.dart';

// 1,5,3,9,8
// [1,3,5] [8,9]
// 1 3 5 8 9

// 1,7,6,18,2,1
// [1,2] [6,7] [18]
// 1 6 7 18 1 2
class Solution {
  List<int> lexicographicallySmallestArray(List<int> nums, int limit) {
    final N = nums.length;
    // You can also use union find to find group id but since union find is not built in dart
    // and the implementation is more complex, so we use sort here
    // https://dart.dev/language/operators#cascade-notation
    final sortedNums = [...nums]..sort();
    final G = List<int>.filled(N, 0), res = List<int>.filled(N, 0);
    for (int i = 1, curId = 0; i < N; ++i) {
        if (sortedNums[i] - sortedNums[i-1] > limit) ++curId;
        G[i] = curId;
    }

    // Use either binary search or a map to map back to group id
    // https://api.flutter.dev/flutter/package-collection_collection/binarySearch.html
    int getGroupId(int target) => G[binarySearch(sortedNums, target)];

    final List<List<int>> LG = [];
    for (int i = 0; i < N; ++i) {
        int groupId = getGroupId(nums[i]);
        while (LG.length <= groupId) LG.add([]);
        LG[groupId].add(i);
    }

    for (final L in LG) {
        final sortedL = [...L]..sort((a, b) => nums[a].compareTo(nums[b]));
        for (int i = 0; i < L.length; ++i) res[L[i]] = nums[sortedL[i]];
    }

    return res;
  }
}
