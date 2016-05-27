class Solution {
public:
    string countAndSay(int n) {
        static std::vector<string> table = {"1", "1"};
        if (n < table.size()) return table[n];
        
        string s = countAndSay(n-1), say;
        char cur = s[0], count = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (i+1 >= s.size()) {
                say = say + std::to_string(count) + cur;
            } else if (s[i+1] == cur) {
                ++count;
            } else {
                say = say + std::to_string(count) + cur;
                cur = s[i+1];
                count = 1;
            }
        }
        
        table.push_back(say);
        return say;
    }
};

