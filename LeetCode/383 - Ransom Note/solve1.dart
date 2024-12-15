class Solution {
  bool canConstruct(String ransomNote, String magazine) {
    // https://api.dart.dev/dart-collection/HashMap-class.html
    final m = Map<String, int>();
    // https://stackoverflow.com/questions/56943363/dart-map-increment-the-value-of-a-key
    for (int i = 0; i < magazine.length; ++i)
        m.update(magazine[i], (value) => ++value, ifAbsent: () => 1);
    for (int i = 0; i < ransomNote.length; ++i) {
        String c = ransomNote[i];
        if (!m.containsKey(c) || m[c] == 0)
            return false;
        m[c] = m[c]! - 1;
    }
    return true;
  }
}
