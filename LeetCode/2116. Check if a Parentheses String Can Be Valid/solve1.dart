class Solution {
  bool canBeValid(String s, String locked) {
    final N = s.length;
    if (s.length % 2 == 1) return false;
    int nL = 0, nFree = 0, nR = 0;
    for (int i = 0; i < N; ++i) {
        if (locked[i] == '1') {
            if (s[i] == '(') ++nL;
            else ++nR;
        } else ++nFree;
        if (nR > nFree + nL) return false;
    }
    nL = 0; nFree = 0; nR = 0;
    for (int i = N-1; i >= 0; --i) {
        if (locked[i] == '1') {
            if (s[i] == '(') ++nL;
            else ++nR;
        } else ++nFree;
        if (nL > nFree + nR) return false;
    }
    return true;
  }
}


