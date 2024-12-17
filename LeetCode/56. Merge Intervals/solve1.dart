class Solution {
  List<List<int>> merge(List<List<int>> intervals) {
    // https://api.flutter.dev/flutter/dart-core/List/sort.html
    intervals.sort((a, b) => a[0].compareTo(b[0]));
    int last = -1;
    final List<List<int>> res = [];
    for (final [a, b] in intervals) {
        if (a <= last) {
            last = max(res.last[1], b);
            res.last[1] = last;
        } else {
            res.add([a, b]);
            last = b;
        }
    }
    return res;
  }
}
