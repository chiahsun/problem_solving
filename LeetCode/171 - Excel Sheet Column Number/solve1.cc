class Solution {
public:
    int titleToNumber(string s) {
        int x = 0;
        for (int i = 0; i < s.size() ; ++i) {
            x *= 26;
            x += (s[i] - 'A' + 1);
        }
        return x;
    }
};
