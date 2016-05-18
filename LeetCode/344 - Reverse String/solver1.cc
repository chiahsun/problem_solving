class Solution {
public:
    string reverseString(string s) {
        for (int i = 0; i < s.size()/2; ++i)
            std::swap(s[i], s[s.size()-i-1]);
        return s;
    }
};
