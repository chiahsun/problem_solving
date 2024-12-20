import 'package:collection/collection.dart';

class Solution {
  int kthFactor(int n, int k) {
    List<int> divisors = [];
    int a = n;
    for (int d = 2; a > 1 && d*d <= n; ++d) {
        if (a % d == 0) {
            divisors.add(d);
            while (a % d == 0) a ~/= d;
        }
    }
    if (a != 1) divisors.add(a);

    final pq = PriorityQueue<int>();
    pq.add(1);
    Set<int> factors = {1};
    for (int i = 1; !pq.isEmpty; ++i) {
        final v = pq.removeFirst();
        if (i == k) return v;
        final left = n ~/ v;
        for (final d in divisors) {
            final next = v * d;
            if (left % d == 0 && !factors.contains(next)) {
                factors.add(next);
                pq.add(next);
            }
        }
    }
    return -1;
  }
}
