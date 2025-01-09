class Solution {
  int prefixCount(List<String> words, String pref) {
    // https://api.flutter.dev/flutter/dart-core/Iterable/fold.html
    return words.fold(0, (accu, elem) => accu + (elem.startsWith(pref) ? 1 : 0));
  }
}
