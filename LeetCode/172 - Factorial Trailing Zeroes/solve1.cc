class Solution {
public:
    int trailingZeroes(int n) {
        int now = 5, cur;
        int sum = 0;
        while ((cur = n/now)) {
            int prev_now = now;
            sum += cur;
            now *= 5;
            if (now /5 != prev_now)
                break;
        }
        return sum;
    }
};
