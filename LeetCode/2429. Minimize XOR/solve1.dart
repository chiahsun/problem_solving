// 011
// 101

// 01001
// 11100
// 01011

// 0001
// 1100
class Solution {
  int countBits(int x) {
    int cnt = 0;
    while (x > 0) {
        x &= (x-1);
        ++cnt;
    }
    return cnt;
  }
  int minimizeXor(int num1, int num2) {
    final M = countBits(num1), N = countBits(num2);
    if (M >= N) {
        int mask = 1, cnt = M-N;
        while (cnt > 0) {
            if ((mask & num1) != 0) {
                --cnt;
                num1 ^= mask;
            }
            mask <<= 1;
        }
    } else {
         int mask = 1, cnt = N-M;
        while (cnt > 0) {
            if ((mask & num1) == 0) {
                --cnt;
                num1 |= mask;
            }
            mask <<= 1;
        }
    }
    return num1;
  }
}
