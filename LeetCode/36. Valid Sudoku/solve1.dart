class Solution {
  bool isValidSudoku(List<List<String>> board) {
    final N = board.length;
    for (int i = 0; i < N; ++i) {
        var d = List<bool>.filled(9, false);
        for (int k = 0; k < N; ++k) {
            String c = board[i][k];
            if (c != ".") {
                // https://api.flutter.dev/flutter/dart-core/int/parse.html
                int v = int.parse(c)-1;
                if (d[v]) return false;
                d[v] = true;
            }
        }
        d = List<bool>.filled(9, false);
        for (int k = 0; k < N; ++k) {
            String c = board[k][i];
            if (c != ".") {
                int v = int.parse(c)-1;
                if (d[v]) return false;
                d[v] = true;
            }
        }
    }
    final d1 = [0, 0, 0, 3, 3, 3, 6, 6, 6];
    final d2 = [0, 3, 6, 0, 3, 6, 0, 3, 6];
    for (int m=0; m <9; ++m) {
        final d = List<bool>.filled(9, false);
        for (int i = 0; i < 3; ++i)
            for (int k = 0; k < 3; ++k) {
                String c = board[i+d1[m]][k+d2[m]];
                if (c != ".") {
                    int v = int.parse(c)-1;
                    if (d[v]) return false;
                    d[v] = true;
                }
            }
    }
    return true;
  }
}
