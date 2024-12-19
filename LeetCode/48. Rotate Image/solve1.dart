class Solution {
  void rotate(List<List<int>> matrix) {
    final N = matrix.length, M = matrix.first.length;
    for (int i = 0; i < (N+1) ~/ 2; ++i) {
        for (int k = i; k < N-i-1; ++k) {
            List<int> nx = [   k,  N-i-1, N-k-1, i];
            List<int> ny = [N-i-1, N-k-1,     i, k];
            int v = matrix[i][k];
            for (int m = 0; m < 4; ++m) {
                final back = matrix[nx[m]][ny[m]];
                matrix[nx[m]][ny[m]] = v;
                v = back;
            }
        }
    }
  }
}

//  1  2  3  4  5     21 16 11  6 1
//  6  7  8  9 10     22 17 12  7 2
// 11 12 13 14 15     23 18 13  8 3
// 16 17 18 19 20     24 19 14  9 4
// 21 22 23 24 25     25 20 15 10 5
