#include <vector>

class ZigZag {
public:
    int longestZigZag(std::vector<int>& sequence) {
        int last = sequence[0];
        int dir = 0;
        int ans = 1;
        for (int a : sequence) {
            if (a > last) {
                if (dir <= 0) { ans++; dir = 1; }
                last = a;
            } else if (a < last) {
                if (dir >= 0) { ans++; dir = -1; }
                last = a;
            }
        }
        return ans;
    }
};