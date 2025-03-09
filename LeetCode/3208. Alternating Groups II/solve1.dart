class Solution {
  int numberOfAlternatingGroups(List<int> colors, int k) {
    final N = colors.length;
    int start = 0, cnt = 0;
    for (int i = 1; i < N; ++i) {
        if (colors[i] == colors[i-1]) start = i;
        if (i - start + 1 >= k) ++cnt;
    }
    for (int i = N; i < N+k-1; ++i) {
        final oriPos = i % N, oriPosPrev = (i - 1) % N;
        if (colors[oriPos] == colors[oriPosPrev]) start = i;
        if (i - start + 1 >= k) ++cnt;
    }
    return cnt;
  }
}
