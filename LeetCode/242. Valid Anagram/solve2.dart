class Solution {
  bool isAnagram(String s, String t) {
    final m = List<int>.filled(26, 0);
    // https://api.dart.dev/stable/3.1.3/dart-core/Iterable/forEach.html
    s.codeUnits.forEach((v) { m[v - 97] += 1; });
    t.codeUnits.forEach((v) { m[v - 97] -= 1; });
    return m.every((v) => v == 0);
  }
}
