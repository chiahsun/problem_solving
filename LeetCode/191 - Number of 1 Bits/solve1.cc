class Solution {
public:
    int hammingWeight(uint32_t n) {
        int mask = 0x1;
        int cnt = 0;
        for (int i = 0; i < 32; ++i, mask <<= 1) {
            if (mask & n) ++cnt;
        }
        return cnt;
    }
};
