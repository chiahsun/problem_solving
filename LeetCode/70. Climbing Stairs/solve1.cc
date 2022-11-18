class Solution {
public:
    int climbStairs(int n) {
        if (n < 4) return n;
        int f2 = 2, f3 = 3;
        int res = 0;
        for (int i = 3; i < n; ++i) {
            res = f2 + f3;
            f2 = f3;
            f3 = res;
        }
            
        return res;
    }
};
