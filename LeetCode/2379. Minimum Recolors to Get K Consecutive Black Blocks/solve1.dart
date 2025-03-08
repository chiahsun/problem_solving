// WBBWWBBWBW
// 1234567
// 1112333445
class Solution {
  int minimumRecolors(String blocks, int k) {
    final N = blocks.length, L = List<int>.filled(N, 0);
    for (int i = 0, cnt = 0; i < N; ++i) {
        if (blocks[i] == 'W') ++cnt;
        L[i] = cnt;
    }
    int res = L[k-1];
    for (int i = k; i < N; ++i)
        res = min(res, L[i] - L[i-k]);
    return res;
  }
}
