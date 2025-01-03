// 0,1,0,2,1,0,1,3,2,1,2,1
// 3 3 3 3 3 3 3 3 2 2 2 1 R
// 0 1 1 2 2 2 2 3 3 3 3 3 L
// 0 0 1 0 1 2 1 0 0 1 0 0
class Solution {
  int trap(List<int> height) {
    final N = height.length;
    final R = List<int>.filled(N+1, 0);
    for (int i = N-1; i >= 0; --i) {
        final cur = height[i];
        R[i] = max(R[i+1], cur);
    }
    int res = 0, L = 0;
    for (int i = 0; i < N; ++i) {
        final cur = height[i];
        L = max(L, cur);
        res += (min(L, R[i]) - cur);
    }
    return res;
  }
}
