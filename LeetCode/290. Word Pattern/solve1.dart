class Solution {
  bool wordPattern(String pattern, String s) {
    final notFound = ' ';
    // https://api.dart.dev/dart-core/Iterable/toList.html
    final p = pattern.codeUnits.map((c) => c - 97).toList();
        // https://api.flutter.dev/flutter/dart-core/String/split.html
    final strs = s.split(' ');
    if (p.length != strs.length) return false;

    final d = List<String>.filled(26, notFound);
    final mapped = Set<String>();
    for (int i = 0; i < p.length; ++i) {
        final key = p[i];
        if (d[key] != notFound) {
            if (d[key] != strs[i])
                return false;
        } else {
            final value = strs[i];
            if (mapped.contains(value)) return false;
            mapped.add(value);
            d[key] = value;
        }
    }
    return true;
  }
}
