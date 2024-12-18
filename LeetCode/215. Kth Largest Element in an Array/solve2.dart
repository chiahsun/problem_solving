import 'package:collection/collection.dart';

class Solution {
  int findKthLargest(List<int> nums, int k) {
    // https://api.flutter.dev/flutter/package-collection_collection/HeapPriorityQueue-class.html
    final heap = HeapPriorityQueue();
    for (final n in nums) {
        heap.add(n);
        if (heap.length > k) {
            heap.removeFirst();
        }
    }
    return heap.first;
  }
}
