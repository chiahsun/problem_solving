class Solution {
  bool isHappy(int n) {
    final s = Set<int>();
    while (n != 1) {
        if (s.contains(n)) return false;
        s.add(n);
        int next = 0;
        while (n > 0) {
            int digit = n % 10;
            next += digit * digit;
            n ~/= 10;
        }
        n = next;
    }
    return true;
  }
}
