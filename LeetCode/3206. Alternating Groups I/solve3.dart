class Solution {
  int numberOfAlternatingGroups(List<int> colors) {
    final N = colors.length;
    var prevOk = colors[0] != colors[N-1], cnt = 0;

    for (int i = 0; i < N; ++i) {
        final next = (i == N-1) ? 0 : i+1, curOk = colors[i] != colors[next];
        if (prevOk && curOk) ++cnt;
        prevOk = curOk;
    }
     
    return cnt;
  }
}
