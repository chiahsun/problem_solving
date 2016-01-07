class Solution {
public:
    int hammingWeight(uint32_t n) {
        const int filter[4] = { 0xff, 0xff00, 0xff0000, 0xff000000 };
        int mask[4] = {0x1, 0x100, 0x10000, 0x1000000};
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            if (n & filter[i]) {
                for (int k = 0; k < 8; ++k, mask[i] <<= 1)
                    if (mask[i] & n)
                        ++cnt;
            }
        }
        return cnt;
    }
};
