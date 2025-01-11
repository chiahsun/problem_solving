// aa nn ee ll
// b

// ee
// l t c o d e


// af k = 3
// affa k = 3

class Solution {
  bool canConstruct(String s, int k) {
    if (s.length < k) return false;
    final cnts = List<int>.filled(26, 0);
    for (int i = 0; i < s.codeUnits.length; ++i) {
        ++cnts[s.codeUnits[i] - 97];
    }
    int nSingles = 0;
    for (int i = 0; i < 26; ++i)
        if (cnts[i] % 2 == 1)
            ++nSingles;
    return nSingles <= k;
  }
}
