class Solution {
  bool searchMatrix(List<List<int>> matrix, int target) {
    final M = matrix.length, N = matrix.first.length;
    int lo = 0, hi = M-1;
    if (target < matrix.first.first || target > matrix.last.last) return false;
    var chosenRow = 0;
    while (true) {
        int mid = lo + (hi - lo) ~/ 2;
        if (target < matrix[mid].first)     hi = mid-1;
        else if (target > matrix[mid].last) lo = mid+1;
        else                                { chosenRow = mid; break; }
        if (lo > hi) return false;
    }

    if (target < matrix[chosenRow].first || target > matrix[chosenRow].last) return false;
    lo = 0;
    hi = N-1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) ~/ 2;
        if (target == matrix[chosenRow][mid]) return true;
        if (target < matrix[chosenRow][mid]) hi = mid-1;
        else                                 lo = mid+1;
    }
    return false;
  }
}
