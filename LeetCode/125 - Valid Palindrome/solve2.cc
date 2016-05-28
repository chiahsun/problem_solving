class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            while (l < s.size() and not isalnum(s[l])) ++l;
            while (r >= 0 and not isalnum(s[r])) --r;
            if (r < 0 or l >= s.size()) break;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            ++l, --r;
        }
        return true;
    }
};
