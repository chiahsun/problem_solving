// [1  6]
//   [2   8]
//      [7   12]
//         [10   16]
class Solution {
  int findMinArrowShots(List<List<int>> points) {
    points.sort((a, b) => a[0].compareTo(b[0]));
    int start = points.first[0], end = points.first[1];
    int res = 1;
    for (int i = 1; i < points.length; ++i) {
        if (points[i][0] > end) {
            ++res;
            start = points[i][0];
            end = points[i][1];
        }
        else {
            start = max(start, points[i][0]);
            end = min(end, points[i][1]);
        }
    }

    return res;
  }
}
