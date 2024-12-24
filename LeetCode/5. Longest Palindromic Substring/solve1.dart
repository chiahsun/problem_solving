class Solution {
  String longestPalindrome(String s) {
    String res = s[0];
    int cnt = 0;
    final N = s.length;

    // b a b
    void checkSingle(int i, int d) {
        if (i - d < 0 || i + d >= N) return;
        if (s[i+d] != s[i-d]) return;
        for (int k = 1; k <= d-1; ++k) {
            if (s[i+k] != s[i-k]) return;
        }

        for (int k = d; i-k >= 0 && i+k < N && s[i+k] == s[i-k]; ++k) {
            int cur = 2*k+1 ;
            if (cur > cnt) {
                cnt = cur;
                res = s.substring(i-k, i+k+1);
            }
        }
    }

    //   0 1 2
    // b a a b
    void checkDouble(int i, int d) {
        int k = i+1;
        if (i - d < 0 || k + d >= N) return;
        if (s[i-d] != s[k+d]) return;
        for (int m = 0; m < d; ++m) {
            if (s[i-m] != s[k+m]) return;
        }
        for (int m = d; i-m >= 0 && k+m < N && s[i-m] == s[k+m]; ++m) {
            int cur = 2*m+2;
            if (cur > cnt) {
                cnt = cur;
                res = s.substring(i-m, k+m+1);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        checkSingle(i, (cnt+1)~/2);
        checkDouble(i, cnt~/2);
    }

    return res;
  }
}
