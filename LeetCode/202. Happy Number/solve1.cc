class Solution {
public:
    int next(int x) { 
        int sum = 0;
        while (x > 0) { 
            int digit = (x % 10); 
            sum += (digit * digit);
            x /= 10; 
        }
        return sum;
    }
    bool isHappy(int n) {
        if (n <= 0) return false;
        int x = next(n);
        int y = next(next(n));
        while (x != y) {
            x = next(x);
            y = next(next(y));
        }
        return (x == 1);
    }
};
