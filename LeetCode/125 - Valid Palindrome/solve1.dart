class Solution {
  bool isPalindrome(String s) {
    var v = s.codeUnits;
    var i = 0, k = s.length - 1;
    bool is_alphanumeric(int v) {
        return (v >= 48 && v <= 57) || (v >= 65 && v <= 90) || (v >= 97 && v <= 122);
    }
    while (i < k) {
        while (i < s.length && !is_alphanumeric(v[i])) ++i;
        while (k > i && !is_alphanumeric(v[k])) --k;
        if (i >= k) break;
        var a = v[i], b = v[k];
        if (v[i] >= 65 && v[i] <= 90) a = v[i] - 65 + 97;
        if (v[k] >= 65 && v[k] <= 90) b = v[k] - 65 + 97;
        if (a != b) return false;
        i++; k--;
    }
    return true;
  }
}
