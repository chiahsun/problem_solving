// import 'dart:collection';
import 'package:collection/collection.dart';
// [1, 2, 3] [7, 16, 17] k = 3
// [1 7] [2 7] [3 7] [1 16] ...
// [[7], [0, 0]]

class Solution {
  List<List<int>> kSmallestPairs(List<int> nums1, List<int> nums2, int k) {
    final pq = PriorityQueue((List<List<int>> a, List<List<int>> b) => a[0][0].compareTo(b[0][0]));
    final List<List<int>> res = [];
    final M = nums1.length, N = nums2.length;
    for (int i = 0; i < M; ++i) {
        pq.add([[nums1[i] + nums2[0]], [i, 0]]);
    }
    while (!pq.isEmpty) {
        final minElem = pq.removeFirst();
        final firstPos = minElem[1][0], secondPos = minElem[1][1];
        res.add([nums1[firstPos], nums2[secondPos]]);
        if (res.length >= k) break;
        if (secondPos+1 < N) {
            pq.add([[nums1[firstPos] + nums2[secondPos+1]], [firstPos, secondPos+1]]);
        }
    }
    return res;
  }
}
