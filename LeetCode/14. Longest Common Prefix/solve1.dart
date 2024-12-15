class Solution {
  String longestCommonPrefix(List<String> strs) {
    // https://api.dart.dev/dart-core/Iterable/every.html
    int cnt = 0;
    final minLen = strs.map((s) => s.length).reduce(min);
    for (int i = 0; i < minLen; ++i) {
        String c = strs.first[i];
        if (strs.every((s) => s[i] == c)) ++cnt;
        else break;
    }
    // https://api.flutter.dev/flutter/dart-core/String/substring.html
    return strs.first.substring(0, cnt);
  }
}
