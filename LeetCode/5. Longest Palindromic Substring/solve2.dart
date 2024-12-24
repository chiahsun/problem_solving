class Solution {
  String longestPalindrome(String s) {
    String res = s[0];
    int cnt = 0;
    final N = s.length;

    void check(int i, int k, int d) {
        if (i - d < 0 || k + d >= N) return;
        if (s[i-d] != s[k+d]) return;
        for (int m = 0; m < d; ++m) {
            if (s[i-m] != s[k+m]) return;
        }
        for (int m = d; i-m >= 0 && k+m < N && s[i-m] == s[k+m]; ++m) {
            final cur = k+m-i+m+1;
            if (cur > cnt) {
                cnt = cur;
                res = s.substring(i-m, k+m+1);
            }
        }
    }

    final M = N ~/ 2;
    for (int i = M; i < N; ++i) {
        check(i, i, (cnt+1)~/2);
        check(i, i+1, cnt~/2);
    }
     for (int i = 0; i < M; ++i) {
        check(i, i, (cnt+1)~/2);
        check(i, i+1, cnt~/2);
    }

    return res;
  }
}
