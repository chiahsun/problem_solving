class Solution {
  int singleNumber(List<int> nums) {
    List<int> bits = List<int>.filled(32, 0);
    final zero = BigInt.from(0).toUnsigned(32);
    var mask = BigInt.from(1).toUnsigned(32);
    // https://api.flutter.dev/flutter/dart-core/BigInt/toUnsigned.html
    for (int i = 0; i < 32; ++i, mask<<=1) {
        for (final n in nums) {
            final cur = BigInt.from(n).toUnsigned(32);
            if ((mask & cur) > zero) {
                bits[i] = (bits[i] + 1) % 3;
            }
        }
    }
    int m = 1, res = 0;
    for (int i = 0; i < 32; ++i, m <<= 1) {
        if (bits[i] > 0)
            res |= m;
    }
    return res.toSigned(32);
  }
}
