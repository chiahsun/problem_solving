import 'package:collection/collection.dart';

class Project {
    final int profit, capital;
    Project(this.profit, this.capital);
}

class Solution {
  int findMaximizedCapital(int k, int w, List<int> profits, List<int> capital) {
    final profitPQ = PriorityQueue((Project a, Project b) {
        if (a.profit == b.profit) return 0;
        return (a.profit > b.profit) ? -1 : 1;
    });
    final capitalPQ = PriorityQueue((Project a, Project b) {
        if (a.capital == b.capital) return 0;
        return (a.capital < b.capital) ? -1 : 1;
    });
    for (int i = 0; i < profits.length; ++i)
        capitalPQ.add(Project(profits[i], capital[i]));

    for (int i = 0; i < k; ++i) {
        while (!capitalPQ.isEmpty && capitalPQ.first.capital <= w)
            profitPQ.add(capitalPQ.removeFirst());
        if (profitPQ.isEmpty) break;
        if (profitPQ.first.capital > w) break;
        w += profitPQ.removeFirst().profit;
    }
    return w;
  }
}
