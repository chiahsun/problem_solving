class Solution {
  String findDifferentBinaryString(List<String> nums) {
    final N = nums.first.length;
    List<String> st = [];
    String backtracking() {
        String s = '';
        if (st.length == N) {
            s = st.join('');
            return nums.contains(s) ? '' : s;
        }
        for (final c in ['0', '1']) {
            st.add(c);
            if ((s = backtracking()) != '') return s;
            st.removeLast();
        }
        return '';
    }
    return backtracking();
  }
}
