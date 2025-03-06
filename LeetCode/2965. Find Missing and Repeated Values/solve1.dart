class Solution {
  List<int> findMissingAndRepeatedValues(List<List<int>> grid) {
    final N = grid.length;
    final L = List.filled(N*N, false), M = L.length;
    int a = -1, b = -1, total = 0;
    for (final row in grid) {
        for (final x in row) {
            total += x;
            if (L[x-1]) a = x;
            else        L[x-1] = true;
        }
    }
    return [a, (M+1)*M ~/ 2 - total + a];
  }
}
