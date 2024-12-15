class Solution {
  bool isAnagram(String s, String t) {
    // https://api.flutter.dev/flutter/dart-core/List/sort.html
    // https://api.flutter.dev/flutter/dart-core/Iterable/join.html

    // https://dart.dev/tools/linter-rules/cascade_invocations
    // https://dart.dev/effective-dart/design#avoid-returning-this-from-methods-just-to-enable-a-fluent-interface
    // https://dart.dev/resources/dart-cheatsheet#cascades
    return (s.split('')..sort()).join('') == (t.split('')..sort()).join('');
  }
}
