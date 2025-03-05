// 1 : 1
// 2:  1+2*4-4=5
// 3:  5+3*4-4=13
// Solve the recurrence relation:
// f(1) = 1
// f(n) = f(n-1) + 4(n-1)
// We can get 2n(n-1) + 1
class Solution {
  int coloredCells(int n) {
    return 2 * n * (n-1) + 1;
  }
}
