class Solution {
  List<List<String>> groupAnagrams(List<String> strs) {
    final Map<String, int> m = {};
    final List<List<String>> res = [];
    for (int i = 0; i < strs.length; ++i) {
        final s1 = strs[i];
        final s2 = (s1.split('')..sort()).join();
        if (m.containsKey(s2)) {
            res[m[s2]!].add(s1);
        } else {
            m[s2] = res.length;
            res.add([s1]);
        }
    }
    return res;
  }
}
