class Solution {
  bool isMatch(int target) {
    bool backtracking(int cur, int left) {
        if (cur == left) return true;
        if (cur == 0) return false;
        for (int mod = 10; ; mod *= 10) {
            int a = cur % mod;
            if (left < a) break;
            if (backtracking(cur ~/ mod, left - a)) return true;
            if (a == cur) break;
        }
        return false;
    }

    return backtracking(target * target, target);
  }

  int punishmentNumber(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (isMatch(i)) res += (i * i);
    }
    return res;
  }
}
