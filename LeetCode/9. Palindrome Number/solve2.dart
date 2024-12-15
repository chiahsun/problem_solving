class Solution {
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int mul1 = 1, mul2 = 1;
    while (x ~/ mul1 >= 10) mul1 *= 10;
    while (mul1 > mul2) {
        int a = (x ~/ mul1) % 10, b = (x ~/ mul2) % 10;
        if (a != b) return false;
        mul1 ~/= 10; mul2 *= 10;
    }
    return true;
  }
}
