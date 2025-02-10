class Solution {
  String clearDigits(String s) {
    List<String> st = [];
    final digits = "0123456789".split('');
    for (int i = 0; i < s.length; ++i) {
        String c = s[i];
        if (digits.contains(c)) st.removeLast();
        else                    st.add(c);
    }
    return st.join('');
  }
}
