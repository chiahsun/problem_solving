class Solution {
  int prefixCount(List<String> words, String pref) {
    int cnt = 0;
    for (final word in words) {
        // https://api.flutter.dev/flutter/dart-core/String/starts
        if (word.startsWith(pref))
            ++cnt;
    }
    return cnt;
  }
}
