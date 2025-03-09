class Solution {
  int numberOfAlternatingGroups(List<int> colors) {
    final N = colors.length;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        final prev = (i > 0) ? (i - 1) : (N - 1);
        final next = (i == N-1) ? 0 : (i + 1);
        if (colors[i] != colors[prev] && colors[i] != colors[next])
            ++cnt;
    }
    return cnt;
  }
}
