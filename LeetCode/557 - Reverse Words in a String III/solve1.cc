class Solution {
public:
    void reverseString(std::string & s, int lo, int hi) {
        const int sum = lo + hi;
        for (int i = lo; i <= (lo+hi)/2; ++i) {
            std::swap(s[i], s[sum-i]);
        }
    }
    string reverseWords(string s) {
        int begin = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (i > begin) reverseString(s, begin, i-1);
                begin = i+1;
            }
        }
        if (begin < s.size()) reverseString(s, begin, s.size()-1);
        
        return s;
    }
};
