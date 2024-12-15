class Solution {
  List<int> plusOne(List<int> digits) {
    int carry = 1;
    for (int i = digits.length-1; i >= 0; --i) {
        carry += digits[i];
        digits[i] = carry % 10;
        carry ~/= 10;
        if (carry == 0) break;
    }
    if (carry > 0) digits = [1] + digits;
    return digits;
  }
}
