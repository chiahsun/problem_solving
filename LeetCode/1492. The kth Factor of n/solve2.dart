import 'package:collection/collection.dart';

class Solution {
  int kthFactor(int n, int k) {
    List<int> divisors = [];
    int divisor = 2, a = n;
    while (a > 1) {
        if (a % divisor == 0) {
            divisors.add(divisor);
            int cnt = 0;
            while (a % divisor == 0) {
                a ~/= divisor; ++cnt;
            }
        }
        ++divisor;
    }
    final pq = PriorityQueue<int>();
    pq.add(1);
    Set<int> factors = {};
    for (int i = 1; !pq.isEmpty; ++i) {
        final v = pq.removeFirst();
        if (!factors.contains(v)) {
            factors.add(v);
            if (factors.length == k) return v;
            final left = n ~/ v;
            for (final d in divisors)
                if (left % d == 0)
                     pq.add(v * d);
        }
    }
    return -1;
  }
}
