class Solution {
  List<List<int>> insert(List<List<int>> intervals, List<int> newInterval) {
    List<List<int>> res = [];
    int i = 0;
    final N = intervals.length;
    while(i < N && intervals[i][1] < newInterval[0]) {
        res.add(intervals[i]);
        ++i;
    }
    if (i >= N) return res + [newInterval];
    int start = min(intervals[i][0], newInterval[0]);
    int k = i;
    while (k < N && intervals[k][0] <= newInterval[1]) ++k;

    if (k-1 >= 0) {
        int end = max(intervals[k-1][1], newInterval[1]);
        res.add([start, end]);
    } else {
        res.add(newInterval);
    }
    if (k < N) res = res + intervals.sublist(k);

    return res;
  }
}
