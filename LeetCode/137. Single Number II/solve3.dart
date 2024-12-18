//     ones twos
// 10
//       10
// 10    00   10
// 11    11   10
//       01   00
// 10    11   00

//  one n ones ^ n ~  c
//    0 0     0    1  0 0
//    1 0     1    0  1 0
//    1 1     0    1  0 1
//    0 1     1    0  1 0
class Solution {
  int singleNumber(List<int> nums) {
    int ones = 0, twos = 0;
    for (final n in nums) {
        twos ^= (~(ones ^ n) & n);
        ones ^= n;
        // print('twos: $twos ones: $ones');
        int tmp = (~(ones ^ twos) & twos);
        ones ^= tmp;
        twos ^= tmp;
    }
    return ones;
  }
}
