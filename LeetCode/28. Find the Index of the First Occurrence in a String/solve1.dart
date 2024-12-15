class Solution {
  int strStr(String haystack, String needle) {
    final N = needle.length;
    for (int i = 0; i <= haystack.length - N; ++i) {
        if (haystack.substring(i, i+N) == needle)
            return i;
    }
    return -1;
  }
}
