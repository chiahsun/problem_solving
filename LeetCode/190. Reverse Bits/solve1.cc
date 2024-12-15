#include <iostream>
#include <string>

#define DEBUG_EXPR(expr) do { std::cout << "*Debug: " << #expr << " : " << (expr) << std::endl; } while (0)

std::string get_bit_string(int x) {
    std::string s;
    for (int i = 31; i >= 0; --i) {
        s += std::to_string((x & (1 << i)) > 0);
    }
    return s;
}

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t mask1 = 0x1;
        uint32_t mask2 = 0x1 << 31; // *Important* int would overflow and becomes 0
        for (int i = 0; i < 16; ++i) {
            bool diff = (((n & mask1) > 0) ^ ((n & mask2) > 0));
//            std::cout << "bit " << i << " : " << ((n & mask1) > 0) << "  bit " << (31-i) << " : " << ((n & mask2) > 0) << std::endl;
            if (diff) { n ^= mask1; n ^= mask2; }

//            std::cout << "mask1 : " << get_bit_string(mask1) << std::endl;
//            std::cout << "mask2 : " << get_bit_string(mask2) << std::endl;
            mask1 <<= 1; mask2 >>= 1;
        }
        return n;
    }
};

int main() {
    int x = 43261596; 
    std::cout << "reverse of " << x << " -> " << (Solution()).reverseBits(x) << std::endl;
    return 0;
}
