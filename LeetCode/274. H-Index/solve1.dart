import 'dart:collection';

class Solution {
  int hIndex(List<int> citations) {
    citations.sort();
    int cur = 0, res = 0;
    // https://api.flutter.dev/flutter/dart-collection/Queue-class.html
    final queue = ListQueue<int>();
    for (final c in citations) {
        if (c < cur) continue;
        queue.addLast(c);
        if (queue.length > cur)
            ++cur;
        while (!queue.isEmpty && queue.first < cur) {
            queue.removeFirst();
        }
        res = max(res, min(queue.length, cur));
    }
    return res;
  }
}
