class Solution {
  bool isSubsequence(String s, String t) {
    int i = 0;
    // https://stackoverflow.com/questions/9286885/how-to-iterate-over-a-string-char-by-char-in-dart
    for (int k = 0; k < t.length; ++k) {
        if (i >= s.length)
            break;
        final c = t[k];
        if (s[i] == c) i++;
    }
    return i >= s.length;
  }
}
