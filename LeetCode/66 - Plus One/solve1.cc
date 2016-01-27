class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i = 0; i < digits.size(); ++i) {
            carry += digits[i];
            digits[i] = carry % 10;
            carry /= 10;
        }
        if (carry)
            digits.push_back(carry);
        std::reverse(digits.begin(), digits.end());
        return digits;
    }
};
