// 1:3 a: 1 b: 1 c: 1
// 2:6 a [bc]: 2 b[ac]: 2 c[ab]: 2       ab ac ba bc ca cb   4-1 = 2 + 1
// 3:  a: 2+2=4

class Solution {
  List<String> getCandidates(String last) {
    switch(last) {
        case 'a': return ['b', 'c'];
        case 'b': return ['a', 'c'];
        case 'c': return ['a', 'b'];
        default: return ['a', 'b', 'c'];
    }
  }
  String getHappyString(int n, int k) {
     final buf = StringBuffer(); --k;
     for (var offset = 1 << (n-1), last = ''; offset > 0; offset >>= 1) {
        final pos = k ~/ offset, candidates = getCandidates(last);
        if (pos >= candidates.length) return "";
        last = candidates[pos];
        buf.write(last);
        k %= offset;
     }
     return buf.toString();
  }
}
