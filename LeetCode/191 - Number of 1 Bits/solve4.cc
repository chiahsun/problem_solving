class Solution {
public:
    inline int getLowerCnt(uint32_t x) {
        switch(x) {
            case 0x0:
                return 0;
            case 0x1:
            case 0x2:
            case 0x4:
            case 0x8:
                return 1;
            case 0x3:
            case 0x5:
            case 0x6:
            case 0x9:
            case 0xa:
            case 0xc:
                return 2;
            case 0x7:
            case 0xb:
            case 0xd:
            case 0xe:
                return 3;
            case 0xf:
                return 4;
            default:
                break;
        }
        return 0;
    }
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n != 0) {
            cnt += getLowerCnt(n & 0xf);
            n >>= 4;
        }
        return cnt;
    }
};
