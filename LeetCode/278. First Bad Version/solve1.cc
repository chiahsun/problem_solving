#include <iostream>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
    if (version >= 1702766719) return true;
    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
//            std::cout << l << ", " << r << std::endl;
            int m = l+(r-l)/2;
            if (isBadVersion(m))
                r = m;
            else
                l = m+1;
        }
        return l;
    }
};

int main() {
    std::cout << (Solution().firstBadVersion(2126753390)) << std::endl; 
    return 0;
}
