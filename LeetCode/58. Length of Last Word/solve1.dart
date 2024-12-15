class Solution {
  int lengthOfLastWord(String s) {
    int end = s.length-1;
    while (end >= 0 && s[end] == ' ') end--;
    if (end < 0) return s.length;
    int begin = end-1;
    while (begin >= 0 && s[begin] != ' ') begin--;
    return end - begin;
  }
}
