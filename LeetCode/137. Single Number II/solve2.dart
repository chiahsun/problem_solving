class Solution {
  int singleNumber(List<int> nums) {
    List<int> bits = List<int>.filled(64, 0);
    int mask = 1;
    for (int i = 0; i < 64; ++i, mask<<=1) {
        for (final n in nums) {
            if ((mask & n) != 0) {
                bits[i] = (bits[i] + 1) % 3;
            }
        }
    }
    int m = 1, res = 0;
    for (int i = 0; i < 64; ++i, m <<= 1) {
        if (bits[i] > 0)
            res |= m;
    }
    return res;
  }
}
