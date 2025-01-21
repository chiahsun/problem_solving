import 'package:collection/collection.dart';

class Solution {
  int gridGame(List<List<int>> grid) {
    int a = grid[0].sum - grid[0].first, b = 0, res = a;

    for (int i = 1; i < grid[0].length; ++i) {
        a -= grid[0][i];
        b += grid[1][i-1];
        res = min(res, max(a, b));
    }

    return res;
  }
}
