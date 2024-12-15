class Solution {
  String reverseWords(String s) {
    return s.split(' ').where((s) => s.length > 0).toList().reversed.toList().join(' ');
  }
}
