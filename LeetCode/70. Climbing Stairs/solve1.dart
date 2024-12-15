class Solution {
  int climbStairs(int n) {
    int a = 1, b = 2;
    while (n > 1) {
        int c = a;
        a = b;
        b += c;
        n--;
    }
    return a;
  }
}
