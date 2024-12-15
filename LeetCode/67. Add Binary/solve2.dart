class Solution {
  String addBinary(String a, String b) {
    int carry = 0, ia = a.length-1, ib = b.length-1;
    List<String> res = [];
    while (carry > 0 || ia >= 0 || ib >= 0) {
        carry = carry + (ia >= 0 ? (a[ia] == "1" ? 1 : 0) : 0) + (ib >= 0 ? (b[ib] == "1" ? 1 : 0) : 0);
        res.add(carry % 2 == 1 ? "1" : "0");
        carry >>= 1; ia--; ib--;
    }
    return res.reversed.join('');
  }
}
