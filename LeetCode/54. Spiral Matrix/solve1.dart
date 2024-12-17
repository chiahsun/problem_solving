class Solution {
  List<int> spiralOrder(List<List<int>> matrix) {
    final M = matrix.length, N = matrix[0].length;
    int left = M * N, pos = 0, i = 0, k = -1, l = 0, r = N, t = M, b = 1;
    final List<int> v = [];
    while (left > 0) {
        switch(pos) {
            case 0: if ((k+1) < r) { v.add(matrix[i][++k]); --left; } else { pos = 1; --r; }
            case 1: if ((i+1) < t) { v.add(matrix[++i][k]); --left; } else { pos = 2; --t; }
            case 2: if ((k-1) >= l) { v.add(matrix[i][--k]); --left; } else { pos = 3; ++l; }
            default: if ((i-1) >= b) { v.add(matrix[--i][k]); --left; } else { pos = 0; ++b; }
        }
    }
    return v;
  }
}
