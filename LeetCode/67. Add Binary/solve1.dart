class Solution {
  String addBinary(String a, String b) {
    List<int> v1 = a.split('').map(int.parse).toList().reversed.toList(),
              v2 = b.split('').map(int.parse).toList().reversed.toList(),
              res = [];
    int carry = 0;
    for (int i = 0; i < max(v1.length, v2.length); ++i) {
        carry = carry + ((i < v1.length) ? v1[i] : 0) + ((i < v2.length) ? v2[i] : 0);
        res.add(carry % 2);
        carry >>= 1;
    }
    if (carry != 0) res.add(1);
    return res.map((v) => "$v").toList().reversed.join('');
  }
}
