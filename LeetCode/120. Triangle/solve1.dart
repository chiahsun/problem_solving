class Solution {
  int minimumTotal(List<List<int>> triangle) {
    for (int i = 1; i < triangle.length; ++i) {
        for (int k = 0; k < i+1; ++k) {
            if (k-1 < 0)     triangle[i][k] += triangle[i-1][k];
            else if (k >= i) triangle[i][k] += triangle[i-1][k-1];
            else             triangle[i][k] += min(triangle[i-1][k], triangle[i-1][k-1]);
        }
    }
    return triangle.last.reduce(min);
  }
}
