class Solution {
  bool isSubstring(String s1, String s2, bool isSuffix) {
    final M = s1.length, N = s2.length;
    if (M > N) return false;
    int start = isSuffix ? N-M : 0;
    for (int i = start; i < start+M; ++i) {
        if (s1[i-start] != s2[i])
            return false;
    }
    return true;
  }
  bool isPrefix(String s1, String s2) => isSubstring(s1, s2, false);
  bool isSuffix(String s1, String s2) => isSubstring(s1, s2, true);
  int countPrefixSuffixPairs(List<String> words) {
    final N = words.length;
    int cnt = 0;
    for (int i = 0; i < N-1; ++i) {
        for (int k = i+1; k < N; ++k) {
            if (isPrefix(words[i], words[k]) && isSuffix(words[i], words[k]))
                ++cnt;
        }
    }
    return cnt;
  }
}
