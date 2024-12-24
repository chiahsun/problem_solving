class Solution {
    // Since ccw is not total ordering, we use y-axis as a cut
    int polarOrdering(List<int> pc, List<int> pa, List<int> pb) {
        final [ax, ay] = [pa[0] - pc[0], pa[1] - pc[1]];
        final [bx, by] = [pb[0] - pc[0], pb[1] - pc[1]];
        if (ay == 0 && by == 0) {
            if (ax > 0 && bx > 0) return 0;
            if (ax < 0 && bx < 0) return 0;
            if (bx < 0) return 1;
            return -1;
        }
        if ((ay > 0 && by > 0) || (ay < 0 && by < 0)) return ccw(pc, pa, pb);
        if (by < 0) return 1;
        return -1;
    }

   // 0: collinear >0: counterclockwise <0: clockwise
   int ccw(List<int> pc, List<int> pa, List<int> pb) => (pa[0] - pc[0]) * (pb[1] - pc[1]) - (pa[1] - pc[1]) * (pb[0] - pc[0]);

  int maxPoints(List<List<int>> points) {
    final N = points.length;
    int res = 1;
    for (int i = 0; i < N; ++i) {
        // https://api.flutter.dev/flutter/dart-core/List/List.generate.html
        List<int> L = List<int>.generate(N, (i) => i, growable: false);
        final [x, y] = [points[i][0], points[i][1]];
        L.sort((a, b) => polarOrdering(points[i], points[a], points[b]));
        int cnt = 1, last = 0;
        for (int k = 0; k < L.length; ++k) {
            final l = L[k];
            if (l != i) {
                if (ccw(points[i], points[last], points[l]) == 0) {
                    cnt += 1;
                    res = max(res, cnt);
                } else {
                    cnt = 2;
                }
                last = l;
            }
        }
    }
    return res;
  }
}
