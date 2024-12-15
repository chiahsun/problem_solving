class Solution {
  bool canConstruct(String ransomNote, String magazine) {
    final m = List<int>.filled(26, 0);
    for (final i in magazine.codeUnits)
        m[i - 97] = m[i - 97] + 1;
    for (final i in ransomNote.codeUnits)  {
        if (m[i - 97] == 0)
            return false;
        m[i - 97] = m[i - 97] - 1;
    }
    return true;
  }
}
