class Solution {
  void setZeroes(List<List<int>> matrix) {
    bool firstRow = false, firstCol = false;
    for (int i = 0; i < matrix.length; ++i) {
        if (matrix[i][0] == 0) {
            firstCol = true;
            break;
        }
    }
    for (int i = 0; i < matrix.first.length; ++i) {
        if (matrix[0][i] == 0) {
            firstRow = true;
            break;
        }
    }
    for (int i = 1; i < matrix.length; ++i) {
        for (int k = 1; k < matrix.first.length; ++k) {
            if (matrix[i][k] == 0) {
                matrix[i][0] = 0;
                matrix[0][k] = 0;
            }
        }
    }
    for (int i = 1; i < matrix.length; ++i) {
        if (matrix[i][0] == 0) {
            for (int k = 0; k < matrix.first.length; ++k) {
                matrix[i][k] = 0;
            }
        }
    }
    for (int i = 1; i < matrix.first.length; ++i) {
        if (matrix[0][i] == 0) {
            for (int k = 0; k < matrix.length; ++k) {
                matrix[k][i] = 0;
            }
        }
    }
    if (firstRow) {
        for (int i = 0; i < matrix.first.length; ++i)
            matrix[0][i] = 0;
    }
    if (firstCol) {
        for (int i = 0; i < matrix.length; ++i) {
            matrix[i][0] = 0;
        }
    }
  }
}
