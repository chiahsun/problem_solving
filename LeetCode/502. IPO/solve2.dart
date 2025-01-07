import 'package:collection/collection.dart';

class Project {
    final int profit, capital;
    Project(this.profit, this.capital);
}

class Solution {
  int findMaximizedCapital(int k, int w, List<int> profits, List<int> capital) {
    final N = profits.length;
    final L = List<int>.generate(N, (i) => i, growable: false);
    L.sort((a, b) => capital[a].compareTo(capital[b]));
    final profitPQ = PriorityQueue((Project a, Project b) {
        if (a.profit == b.profit) return 0;
        return (a.profit > b.profit) ? -1 : 1;
    });
    int pos = 0;

    for (int i = 0; i < k; ++i) {
        while (pos < N && capital[L[pos]] <= w) {
            final cur = L[pos]; pos++;
            profitPQ.add(Project(profits[cur], capital[cur]));
        }
        if (profitPQ.isEmpty) break;
        if (profitPQ.first.capital > w) break;
        w += profitPQ.removeFirst().profit;
    }
    return w;
  }
}
