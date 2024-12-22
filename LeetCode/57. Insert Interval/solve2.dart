class Solution {
  List<List<int>> insert(List<List<int>> intervals, List<int> newInterval) {
    if (intervals.isEmpty) return [newInterval];

    final N = intervals.length, a = newInterval[0], b = newInterval[1];
    if (b < intervals.first[0]) return [newInterval] + intervals;
    if (a > intervals.last[1]) return intervals + [newInterval];

    int i = N-1, k = 0;
    while (i >= 0 && a <= intervals[i][1]) --i;
    while (k < N && b >= intervals[k][0]) ++k;
    List<List<int>> res = [];
    if (i >= 0) res = res + intervals.sublist(0, i+1);
    res = res + [[min(intervals[i+1][0], a), max(intervals[k-1][1], b)]];
    if (k < N) res = res + intervals.sublist(k);
    return res;
  }
}
