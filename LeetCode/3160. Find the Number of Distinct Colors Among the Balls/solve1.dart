// 0 1 2 3 4
// 0 0 0 0 0
//   4        1
//     5      2
//    3       2
//       4    3

// 0 1 2 3 4
// 0 0 0 0 0
// 1          1
//   2        2
//     2      2
//       4    3
//         5  4
class Solution {
  List<int> queryResults(int limit, List<List<int>> queries) {
    final colorCnts = Map<int, int>(), ballColor = Map<int, int>();
    List<int> res = [];
    for (final [ball, color] in queries) {
        var modify = true;
        if (ballColor.containsKey(ball)) {
            if (ballColor[ball] == color) { modify = false; }
            else {
                final oldColor = ballColor[ball]!;
                colorCnts.update(oldColor, (value) => --value, ifAbsent: () => 0,);
                if (colorCnts[oldColor] == 0) colorCnts.remove(oldColor);
            }
        }
        if (modify) {
            ballColor[ball] = color;
            colorCnts.update(color, (value) => ++value, ifAbsent: () => 1,);
        }
        res.add(colorCnts.length);
    }
    return res;
  }
}
