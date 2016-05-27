class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        
        for (int i = 0, carry = 0; i < std::max(a.size(), b.size())+1; ++i) {
            int x = (a.size()-i-1 < a.size()) ? (a[a.size()-i-1] - '0') : 0;
            int y = (b.size()-i-1 < b.size()) ? (b[b.size()-i-1] - '0') : 0;
            carry = carry + x + y;
            if (i != std::max(a.size(), b.size()) or carry)
                res += ((carry % 2 == 0) ? "0" : "1");
            carry = (carry >= 2) ? 1 : 0;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
