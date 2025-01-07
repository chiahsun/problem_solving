class Solution {
  int maximalSquare(List<List<String>> matrix) {
    final M = matrix.length, N = matrix.first.length;
    int res = 0;
    for (int i = M-1; i >= 0; --i) {
        for (int k = N-1; k >= 0; --k) {
            int cur = (matrix[i][k] == '1') ? 1 : 0;
            if (cur == 1) {
                if (i <= M-2 && k <= N-2) {
                    int a = int.parse(matrix[i+1][k]);
                    int b = int.parse(matrix[i][k+1]);
                    int c = int.parse(matrix[i+1][k+1]);
                    cur = 1 + min(a, min(b, c));
                }
                res = max(res, cur);
                matrix[i][k] = cur.toString();
            }
        }
    }
    return res * res;
  }
}
