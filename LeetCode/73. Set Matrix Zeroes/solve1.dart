class Solution {
  void setZeroes(List<List<int>> matrix) {
    final xs = Set<int>();
    final ys = Set<int>();
    for (int i = 0; i < matrix.length; ++i) {
        for (int k = 0; k < matrix.first.length; ++k) {
            if (matrix[i][k] == 0) {
                xs.add(i);
                ys.add(k);
            }
        }
    }
    for (final x in xs) {
        for (int i = 0; i < matrix.first.length; ++i) {
            matrix[x][i] = 0;
        }
    }
    for (final y in ys) {
        for (int i = 0; i < matrix.length; ++i) {
            matrix[i][y] = 0;
        }
    }

  }
}
