class Solution {
  bool isPalindrome(int x) {
    String s = "$x";
    int i = 0, k = s.length-1;
    while (i < k) {
        if (s[i] != s[k]) return false;
        i++; k--;
    }
    return true;
  }
}
