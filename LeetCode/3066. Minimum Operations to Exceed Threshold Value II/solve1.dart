import 'package:collection/collection.dart';

class Solution {
  int minOperations(List<int> nums, int k) {
    final pq = PriorityQueue<int>();
    for (final a in nums) pq.add(a);
    int op = 0;
    for (; pq.length >= 2 && pq.first < k; ++op) {
        final a = pq.removeFirst(), b = pq.removeFirst();
        pq.add(min(a, b) * 2 + max(a, b));
    }
    return op;
  }
}
