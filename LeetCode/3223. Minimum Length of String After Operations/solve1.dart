// 1 3 5 ... -> 1
// 2 4 6 ... -> 2
class Solution {
  int minimumLength(String s) {
    final cnts = List<int>.filled(26, 0);
    for (final code in s.codeUnits) ++cnts[code - 97];
    return cnts.fold(0, (accu, elem) => accu + (elem == 0 ? 0 : (elem % 2 == 1) ? 1 : 2));
  }
}
