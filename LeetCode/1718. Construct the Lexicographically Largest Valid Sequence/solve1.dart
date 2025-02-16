class Solution {
  List<int> constructDistancedSequence(int n) {
    List<bool> used = List.generate(n+1, (i) => false, growable: false);
    final N = 2*n-1;
    List<int> L = List.generate(N, (i) => -1, growable: false), res = [];
    void backtracking(int pos) {
        if (pos == N) {
            res = List.from(L);
            return;
        }
        if (L[pos] != -1) {
            backtracking(pos+1);
            return;
        }
        for (int i = n; i > 0 && res.isEmpty; --i) {
            if (used[i]) continue;
            if (i > 1) if (pos+i >= N || L[pos+i] != -1) continue;
            used[i] = true; L[pos] = i;
            if (i > 1) L[pos+i] = i;
            backtracking(pos+1);
            used[i] = false; L[pos] = -1;
            if (i > 1) L[pos+i] = -1;
        }
    }

    backtracking(0);

    return res;
  }
}
