class Solution {
  List<int> getRepr(String s) {
    final cnts = List<int>.filled(26, 0);
    for (int i = 0; i < s.codeUnits.length; ++i)
        ++cnts[s.codeUnits[i] - 97];
    return cnts;
  }


  List<String> wordSubsets(List<String> words1, List<String> words2) {
    final repr2 = List<int>.filled(26, 0);
    for (final word in words2) {
        final cnts = List<int>.filled(26, 0);
        for (int i = 0; i < word.codeUnits.length; ++i) {
            final cur = word.codeUnits[i] - 97;
            repr2[cur] = max(repr2[cur], ++cnts[cur]);
        }
    }

    List<String> res = [];
    for (final word in words1) {
        final repr = getRepr(word);
        if ([for (int i = 0; i < 26; ++i) i].every((i) => repr[i] >= repr2[i]))
            res.add(word);
    }
    return res;
  }
}
