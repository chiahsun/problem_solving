class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return pow(2, round(log(n)/log(2))) == n;
    }
};
