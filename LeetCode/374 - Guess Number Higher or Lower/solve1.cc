// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            // std::cout << "Guess " << mid << " return " << guess(mid) << std::endl;
            switch(guess(mid)) {
                case -1:
                    hi = mid-1;
                    break;
                case 0:
                    return mid;
                case 1:
                    lo = mid+1;
                    break;
                default:
                    return -1;
            }
        }
        return -1;
    }
};
